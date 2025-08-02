/* 
Explanation of the algorithm:
1. The program evaluates a mathematical expression written in Reverse Polish Notation (RPN).
2. The main function:
   - Reads the RPN expression from the user.
   - Uses a stack to store numbers and perform operations.
   - Iterates through the expression:
     - Pushes numbers onto the stack.
     - Applies operators to the top two numbers on the stack.
   - Handles errors such as invalid characters, stack overflow, and division by zero.
   - Outputs the result of the evaluation.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_STACK = 1000;
    int stack[MAX_STACK];
    int top = -1;

    cout << "Enter RPN expression: ";
    string line;
    getline(cin, line);

    int currentNumber = 0;
    bool buildingNumber = false;

    for (size_t i = 0; i <= line.size(); i++) {
        char c = (i < line.size()) ? line[i] : ' '; 

        if (c >= '0' && c <= '9') {
            currentNumber = currentNumber * 10 + (c - '0');
            buildingNumber = true;
        } else if (c == ' ') {
            if (buildingNumber) {
                if (top == MAX_STACK - 1) {
                    cout << "Error: stack overflow\n";
                    return 1;
                }
                stack[++top] = currentNumber;
                currentNumber = 0;
                buildingNumber = false;
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (buildingNumber) {
                if (top == MAX_STACK - 1) {
                    cout << "Error: stack overflow\n";
                    return 1;
                }
                stack[++top] = currentNumber;
                currentNumber = 0;
                buildingNumber = false;
            }

            if (top < 0) {
                cout << "Error: stack empty, no numbers to operate on\n";
                return 1;
            }

            int result = stack[0];
            for (int j = 1; j <= top; j++) {
                if (c == '+') result += stack[j];
                else if (c == '-') result -= stack[j];
                else if (c == '*') result *= stack[j];
                else if (c == '/') {
                    if (stack[j] == 0) {
                        cout << "Error: division by zero\n";
                        return 1;
                    }
                    result /= stack[j];
                }
            }

            top = 0;
            stack[0] = result;
        } else if (c != '\n' && c != '\r') {
            cout << "Error: invalid character '" << c << "'\n";
            return 1;
        }
    }

    if (top != 0) {
        cout << "Error: invalid expression, more than one number left\n";
        return 1;
    }

    cout << "Result: " << stack[top] << endl;

    return 0;
}

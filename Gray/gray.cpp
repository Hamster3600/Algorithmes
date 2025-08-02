/* 
Explanation of the algorithm:
1. The program converts a binary number to its Gray code representation.
2. The function `binaryStringToDecimal`:
   - Converts a binary string into its decimal equivalent.
   - Iterates through each character of the binary string and calculates the decimal value.
3. The function `decimalToBinaryString`:
   - Converts a decimal number into its binary string representation.
   - Uses a loop to extract binary digits and constructs the binary string.
4. The function `binaryToGray`:
   - Converts a decimal number to its Gray code representation using the formula: `Gray = Binary XOR (Binary >> 1)`.
5. The main function:
   - Prompts the user to input a binary number.
   - Converts the binary number to Gray code and displays the result.
*/

#include <iostream>
#include <string>
using namespace std;

int binaryStringToDecimal(const string& bin) {
    int result = 0;
    for (char c : bin) {
        result = result * 2 + (c - '0');
    }
    return result;
}

string decimalToBinaryString(int num) {
    if (num == 0) return "0";
    string result = "";
    while (num > 0) {
        result = (char)('0' + (num % 2)) + result;
        num /= 2;
    }
    return result;
}

int binaryToGray(int num) {
    return num ^ (num >> 1);
}

int main() {
    string input;
    cout << "Podaj liczbę w postaci binarnej (np. 1010): ";
    cin >> input;

    int decimal = binaryStringToDecimal(input);    
    int gray = binaryToGray(decimal);                
    string grayStr = decimalToBinaryString(gray);   

    cout << "Kod Gray'a (binarnie): " << grayStr << endl;

    return 0;
}

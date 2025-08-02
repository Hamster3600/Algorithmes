/* 
Explanation of the algorithm:
1. The program converts a decimal number into its Binary-Coded Decimal (BCD) representation.
2. The function `decimalDigitToBCD`:
   - Takes a single decimal digit (character) as input.
   - Converts the digit into a 4-bit binary string using bitwise operations.
3. The main function:
   - Prompts the user to input a decimal number as a string.
   - Iterates through each character of the input string.
   - If the character is a valid digit (0-9), it converts it to BCD using `decimalDigitToBCD`.
   - If the character is invalid, it outputs "[?]" to indicate an error.
4. The program outputs the BCD representation of the entire number, with each digit's BCD separated by spaces.
*/

#include <iostream>
#include <string>
using namespace std;

string decimalDigitToBCD(char digitChar) {
    int digit = digitChar - '0';
    string bcdString = "";

    for (int i = 3; i >= 0; i--) {
        bcdString += ((digit >> i) & 1) ? '1' : '0';
    }

    return bcdString;
}

int main() {
    string numberString;
    cout << "Enter a decimal number: ";
    cin >> numberString;

    cout << "BCD: ";
    for (char c : numberString) {
        if (c >= '0' && c <= '9') {
            cout << decimalDigitToBCD(c) << " ";
        } else {
            cout << "[?] ";
        }
    }

    cout << endl;
    return 0;
}
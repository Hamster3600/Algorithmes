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
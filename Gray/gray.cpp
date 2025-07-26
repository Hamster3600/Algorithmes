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

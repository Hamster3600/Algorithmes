#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

std::string decimalToBase(long long decimalNum, int base) {
    if (decimalNum == 0) {
        return "0";
    }
    std::string result = "";
    std::string hexChars = "0123456789ABCDEF";
    while (decimalNum > 0) {
        result = hexChars[decimalNum % base] + result;
        decimalNum /= base;
    }
    return result;
}

long long baseToDecimal(const std::string& numStr, int base) {
    long long decimalNum = 0;
    std::map<char, int> charToVal;
    for (int i = 0; i < 10; ++i) {
        charToVal['0' + i] = i;
    }
    charToVal['A'] = 10; charToVal['B'] = 11; charToVal['C'] = 12;
    charToVal['D'] = 13; charToVal['E'] = 14; charToVal['F'] = 15;

    for (char c : numStr) {
        decimalNum = decimalNum * base + charToVal[toupper(c)];
    }
    return decimalNum;
}

void showMenu() {
    std::cout << "\n--- Konwersja Systemow Liczbowych ---\n";
    std::cout << "1. Konwersja z DEC na BIN/OCT/HEX\n";
    std::cout << "2. Konwersja z BIN/OCT/HEX na DEC (Schemat Hornera)\n";
    std::cout << "3. Wyjscie\n";
    std::cout << "Wybierz opcje: ";
}

int main() {
    int choice;
    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                long long decNum;
                int targetBase;
                std::cout << "Podaj liczbe dziesietna: ";
                std::cin >> decNum;
                std::cout << "Podaj system docelowy (2-BIN, 8-OCT, 16-HEX): ";
                std::cin >> targetBase;
                if (targetBase == 2 || targetBase == 8 || targetBase == 16) {
                    std::cout << "Wynik: " << decimalToBase(decNum, targetBase) << std::endl;
                } else {
                    std::cout << "Nieprawidlowy system docelowy.\n";
                }
                break;
            }
            case 2: {
                std::string numStr;
                int sourceBase;
                std::cout << "Podaj liczbe: ";
                std::cin >> numStr;
                std::cout << "Podaj system zrodlowy (2-BIN, 8-OCT, 16-HEX): ";
                std::cin >> sourceBase;
                if (sourceBase == 2 || sourceBase == 8 || sourceBase == 16) {
                    std::cout << "Wynik: " << baseToDecimal(numStr, sourceBase) << std::endl;
                } else {
                    std::cout << "Nieprawidlowy system zrodlowy.\n";
                }
                break;
            }
            case 3: {
                std::cout << "Do widzenia!\n";
                break;
            }
            default: {
                std::cout << "Nieprawidlowa opcja. Sprobuj ponownie.\n";
                break;
            }
        }
    } while (choice != 3);

    return 0;
}
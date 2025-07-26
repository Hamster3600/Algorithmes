#include <iostream>
#include <string>
using namespace std;

string vernamCipher(const string& text, const string& key) {
    string result = "";
    for (size_t i = 0; i < text.size(); i++) {
        result += text[i] ^ key[i];
    }
    return result;
}

int main() {
    string plaintext, key;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter key (same length): ";
    getline(cin, key);

    if (key.length() != plaintext.length()) {
        cout << "Key must be the same length as plaintext." << endl;
        return 1;
    }

    string ciphertext = vernamCipher(plaintext, key);
    cout << "Ciphertext (may contain unreadable chars): " << ciphertext << endl;

    string decrypted = vernamCipher(ciphertext, key);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}

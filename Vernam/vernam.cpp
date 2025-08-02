/* 
Explanation of the algorithm:
1. The program implements the Vernam cipher for encryption and decryption.
2. The function `vernamCipher`:
   - Takes a plaintext and a key as input.
   - Encrypts or decrypts the text by performing a bitwise XOR operation between each character of the text and the corresponding character of the key.
   - Returns the resulting encrypted or decrypted text.
3. The main function:
   - Prompts the user to input a plaintext and a key.
   - Calls `vernamCipher` to perform encryption or decryption and displays the result.
*/

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

/* 
Explanation of the algorithm:
1. The program implements the columnar transposition cipher for encryption.
2. The function `encrypt`:
   - Takes plaintext and the number of columns (key) as input.
   - Rearranges the characters of the plaintext into columns and reads them column by column.
   - Returns the encrypted text.
3. The main function:
   - Prompts the user to input plaintext and the key.
   - Calls `encrypt` to perform encryption and displays the ciphertext.
*/

#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int cols) {
    string result = "";
    int len = text.length();
    int rows = (len + cols - 1) / cols;

    for (int col = 0; col < cols; col++) {
        for (int row = 0; row < rows; row++) {
            int index = row * cols + col;
            if (index < len) {
                result += text[index];
            }
        }
    }

    return result;
}

int main() {
    string plaintext;
    int key;

    cout << "Enter plaintext (no spaces): ";
    cin >> plaintext;

    cout << "Enter number of columns (key): ";
    cin >> key;

    string ciphertext = encrypt(plaintext, key);

    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}

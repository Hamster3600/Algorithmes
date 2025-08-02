/* 
Explanation of the algorithm:
1. The program implements the Caesar cipher for encryption and decryption.
2. The main function:
   - Prompts the user to input a ciphertext and a key.
   - Defines the alphabet used for encryption and decryption.
   - Iterates through each character of the ciphertext, shifting it by the key to perform encryption or decryption.
   - Displays the resulting text.
*/

#include <string>
#include <iostream>

using namespace std;

int main(){
    string szyfrogram;
    int klucz;

    cout << "Podaj szyfrogram: ";
    getline(cin, szyfrogram);

    cout << "Podaj klucz: ";
    cin >> klucz;


    const string ALPHABET = "ASBCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int ALPHABET_SIZE = ALPHABET.length();


    for(int i = 0; i < szyfrogram.length(); i++){
        char literka = szyfrogram[i];
        for(int j = 0; j < ALPHABET_SIZE; j++){
            if(literka == ALPHABET[j]){
                int index = (j - klucz + ALPHABET_SIZE) % ALPHABET_SIZE;
                szyfrogram[i] = ALPHABET[index];
                break;
            }
        }
    }

    cout << "Odkodowany tekst: " << szyfrogram << endl;

    return 0;
}
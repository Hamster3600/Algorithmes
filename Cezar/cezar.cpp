#include <string>
#include <iostream>

using namespace std;

int main(){
    string szyfrogram;
    int klucz;

    cout << "Podaj szyfrogram: ";
    getline(cin, szyfrogram); // lepszy dla liń

    cout << "Podaj klucz: ";
    cin >> klucz; // lepszy dla cyfr


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
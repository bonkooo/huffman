#include <iostream>
#include <unordered_map>
#include <string>
#include "huffman.h"
using namespace std;

int main() {
    string message, code;
    Node* root = nullptr;
    unordered_map<char, int> frqMap; //mapa gde su parovi karakter i njegova ucestalost u poruci (koristi se za formiranje stabla)
    unordered_map<char, string> codeMap; //mapa gde su parovi karakter i njegov binarni hafmanov kod
    char option;

    do {
        cout << "\nMeni:\n";
        cout << "a - Kodiraj poruku\n";
        cout << "b - Dekodiraj poruku\n";
        cout << "e - Izlaz\n";

        cin >> option; 

        switch (option) {
        case 'a': {
            cout << "Enter message: ";
            cin.ignore(); // Pokupi blanko karaktere
            getline(cin, message); 

            frqMap.clear(); 
            for (char ch : message) {
                frqMap[ch]++;
            }

            root = createTree(frqMap);
            generateCodes(root, "", codeMap);
            code = encode(message, codeMap);

            cout << "Mapa karakter - kod: \n";
            for (auto pair : codeMap) {
                cout << pair.first << " : " << pair.second << '\n';
            }

            cout << "Kodirana poruka: " << code << '\n';
            break;
        }
        case 'b': {
            if (!root) {
                cout << "Prvo unesite poruku pre dekodiranja!\n";
            }
            else {
                cout << "Kodirana poruka: " << code << '\n';
                string decodedMsg = decode(code, root);
                cout << "Dekodirana poruka: " << decodedMsg << '\n';
            }
            break;
        }
        case 'e': {
            cout << "Izlaz...\n";
            break;
        }
        default: {
            cout << "Nepoznata opcija...\n";
            break;
        }
        }
    } while (option != 'e');

    return 0;
}

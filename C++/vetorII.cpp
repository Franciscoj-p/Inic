#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> numeros;
    do {
        cout << "ingrese un numero mayor que 0" << endl; 
        cin >> n;
        if (n == 0) {
            break;
        } 
        numeros.push_back(n);
    } while (n > 0);

    cout << "----------------------" << endl;
    cout << "Los numeros ingresados son: " << endl;
    for (int i = 0; i < numeros.size() ; i++) {
        cout << numeros[i] << endl;
    }
}
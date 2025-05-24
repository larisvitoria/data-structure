#include <iostream>
#include <new>
#include <string>

using namespace std;

int main() {

    try {
        int *p = new int; // Sem inicialização
        cout << "valor: " << *p << "\n";
        cout << "endereco: " << p << "\n";

        *p = 7;
        cout << "valor: " << *p << "\n";
        cout << "endereco: " << p << "\n";
        delete p; // Desalocando

        p = new int {10}; // Inicializando com valor
        // Mesmo que int *p = new int {10};
        cout << "valor: " << *p << "\n";
        cout << "endereco: " << p << "\n";
        delete p;

        double *v = new double [5] {0, 1, 2, 3, 4};

        cout << v[1];

        delete v;

    }

    catch (const bad_alloc &e) {
        cout << "erro! " << e.what() << "\n";
        return 1; 
    }

}
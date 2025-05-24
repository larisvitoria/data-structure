#include <iostream>

using namespace std;

int main() {

   cout << "=== Pointers definition ===\n";

   int i = 10; // Inteiro de valor = 10
   int k = 5;
   int *p; // Ponteiro apontando para nulo
   p = &i; // O ponteiro p recebe o endereço de i

   cout << "i value: " << *p << "\n";
   cout << "i address: " << p << "\n";

   int *q = &i; // Declara e inicializa q apontando para i

   int k, *p2 = &k; // Declara um inteiro k que recebe o endereço dele, e um ponteiro que aponta para k

   cout << "k value: " << k << " and " << *p2 << "\n";

   cout << "k address: " << p2 << "\n";

   double m[10]; // Inicializa um vetor de doubles de tamanho 10
   double *r = &(m[5]); // r aponta para v[5]

   cout << "=== Pointers arithmetic ===\n";

   int v[5] = {0, 1, 2, 3, 4}; // Vetor de 5 inteiros

   int *j = &v[2]; // Ponteiro que aponta para o elemento 2 do vetor

   cout << "v[2]: " << *j << "\n";

   cout << "v[4]: " << *(j + 2) << "\n";

   cout << "v[0]: " << *(j - 2) << "\n";

   cout << "=== Indexing Operator ===" << "\n";

   int *l = &v[0]; // Ponteiro que aponta para o elemento 0 do vetor

   cout << "v[0]: " << l[0] << "\n"; // Elemento 0 do vetor = *(p + 0)

   cout << "v[4]: " << l[4] << "\n"; // Elemento 4 do vetor = *(p + 4)

}
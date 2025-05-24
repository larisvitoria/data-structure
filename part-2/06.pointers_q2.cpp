// Aula 06: Ponteiros, sua aritmética e vetores

// Exercício 2

/*
a) Escreva uma função "int remover_ocorrencias (double v, int n, double x)" que, recebendo um (ponteiro apontando para um) vetor "v" de "n" double's e um double "x", remova as eventuais ocorrências de "x" nas "n" posições do vetor. A função também deve informar a quantidade de números restantes no vetor. Exemplo:
   · Se "n" for 10,
   · "v" possuir os números { 10, 2, -7, 4, 2, 2, 9, 2, 3, 2 }
   · e "x" for 2,
então o estado final do vetor deve ser { 10, -7, 4, 9, 3, ?, ?, ?, ?, ? } e a função deve retornar 5.

b) Analogamente ao exercício anterior, escreva um programa para testar a função acima: leia a entrada do usuário e imprima o resultado ao final.
*/

#include <iostream>

using namespace std;

int remove_ocurrences(double* v, int n, double x) {
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] != x) {
            v[index++] = v[i]; 
        }
    }
    
    return index;
}

int main() {

    double v[10];

    cout << "Digite um numero <= 10: ";
    int n;
    cin >> n;

    cout << "Digite o numero que deseja remover da lista: ";
    double x;
    cin >> x;

    for (int i = 0; i < n; i++) {
        cout << "Digite o valor de v[" << i << "]: ";
        cin >> v[i];
    }

    int index = remove_ocurrences(v, n, x);
    
    cout << "Nova lista: ";

    for (int i = 0; i < index; i++) {
        cout << v[i] << " ";
    }

}
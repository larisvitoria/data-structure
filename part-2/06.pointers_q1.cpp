// Aula 06: Ponteiros, sua aritmética e vetores

// Exercício 1

/*
a) Escreva uma função "void inverter (double *p, int n)" que inverta a ordem dos "n" elementos do vetor (cujo primeiro elemento é) apontado por "p", ou seja, o último número deve passar a estar na primeira posição, o penúltimo na segunda, etc. Utilize a indexação de ponteiros abordada no final da aula de hoje.

b) Escreva em C++ um programa que comece lendo do usuário um inteiro positivo "n", que deve ser no máximo 10. Em seguida, o programa deve ler "n" double's do usuário, armazenando-os num vetor (que, neste exercício, pode ter tamanho exatamente 10, mesmo que apenas as "n" primeiras posições sejam utilizadas). Em seguida, o programa deve inverter a ordem dos "n" números gravados no vetor, chamando a função do item anterior. Por fim, os "n" números do vetor devem ser impressos na tela (ou seja, serão impressos em ordem inversa em relação à ordem de leitura). Importante: embora o efeito externo do programa seja apenas imprimir os números na ordem inversa da leitura, o programa deve funcionar conforme explicado neste enunciado; a intenção do exercício é escrever e testar a função "inverter".
*/

#include <iostream>

using namespace std;

void invert(double *p, int n) { // Recebe o ponteiro p que aponta para o início do vetor e o inteiro n, que armazena o tamanho do vetor
    for (int i = 0; i < n / 2 ; i++) { // Percorre de 0 até o valor anterior a (n / 2)
        double aux = p[i]; // Auxiliar double recebe o valor de *p(p + i) = *p(0 + i)
        p[i] = p[n - 1 - i]; // p[i] recebe o ponteiro oposto no vetor
        p[n - 1 - i] = aux; // O ponteiro oposto recebe o valor armazenado em aux
    }
}

int main() {
    
    double v[10]; // Vetor
    double *p = v; // Mesmo que double *p = &v[0]

    cout << "Digite o valor de um n <= 10: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Digite o valor de v[" << i << "]: ";
        cin >> v[i];
    }

    invert(p, n);

    cout << "Vetor final: \n";

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    };

}
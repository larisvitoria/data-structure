// Expressão numérica com pilhas
// Solução por duas pilhas

#include <iostream>

using namespace std;

const int vector_size = 10;

struct CharPile {
    char vector[vector_size];
    int cont = 0;
};

bool stack(CharPile &pilha, char element) {
    // Checa se está cheia
    if (pilha.cont == vector_size) return false;
    // Insere
    pilha.vector[pilha.cont] = element;
    pilha.cont++;
    return true;
};

bool empty(CharPile &pilha) {
    return pilha.cont == 0;
};

char top(CharPile &pilha) {
    // Checa se está vazia
    if (not empty (pilha)) {
        return pilha.vector[pilha.cont - 1];
    }
    return '0'; // Consideraremos 0 como pilha vazia
};

bool unstack(CharPile &pilha) {
    if (not empty (pilha)) {
        pilha.cont--;
        return true;
    }
    return false;
};

void print_pile (CharPile &pilha) {
    cout << "Pilha: ";
    for (int i = 0; i < pilha.cont; i++) {
        cout << pilha.vector[i] << " ";
    }
    cout << "\n";
};

struct CharPile {
    char vector[vector_size];
    int cont = 0;
};

bool stack(CharPile &pilha, char element) {
    // Checa se está cheia
    if (pilha.cont == vector_size) return false;
    // Insere
    pilha.vector[pilha.cont] = element;
    pilha.cont++;
    return true;
};

bool empty(CharPile &pilha) {
    return pilha.cont == 0;
};

char top(CharPile &pilha) {
    // Checa se está vazia
    if (not empty (pilha)) {
        return pilha.vector[pilha.cont - 1];
    }
    return '0'; // Consideraremos 0 como pilha vazia
};

bool unstack(CharPile &pilha) {
    if (not empty (pilha)) {
        pilha.cont--;
        return true;
    }
    return false;
};

void print_pile (CharPile &pilha) {
    cout << "Pilha: ";
    for (int i = 0; i < pilha.cont; i++) {
        cout << pilha.vector[i] << " ";
    }
    cout << "\n";
};

int main () {

    Pile expressao;
    bool ongoing = true;

    // A variável ongoing é baseada no último fechar de parentêses
    while (ongoing) {

        char element;
        cin << element;



    }

}
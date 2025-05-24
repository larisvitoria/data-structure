#include <iostream>

using namespace std;

const int tamanho = 5;

struct Fila {
    char vetor[tamanho];
    int i = -1;
    int f;
}

bool inserir(Fila &F, char elemento) {
    if cheia(F) return false;
    else if (F.i == -1) {
        F.l = F.i = 0;
    }
    else {
        F.f = (F.f + 1) % tamanho;
    }
    F.vetor[f] = elemento;
    return false;
}

bool cheia(Fila &F) {
    return (F.f + 1) % tamanho == F.i;
}


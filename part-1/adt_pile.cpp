#include <iostream>

using namespace std;

const int vector_size = 5;

struct Pile {
    char vector[vector_size];
    int cont = 0;
};

bool stack(Pile &pilha, char element) {
    // Checa se está cheia
    if (pilha.cont == vector_size) return false;
    // Insere
    pilha.vector[pilha.cont] = element;
    pilha.cont++;
    return true;
};

bool empty(Pile &pilha) {
    return pilha.cont == 0;
};

char top(Pile &pilha) {
    // Checa se está vazia
    if (not empty (pilha)) {
        return pilha.vector[pilha.cont - 1];
    }
    return '0'; // Consideraremos 0 como pilha vazia
};

bool unstack(Pile &pilha) {
    if (not empty (pilha)) {
        pilha.cont--;
        return true;
    }
    return false;
};

void print_pile (Pile &pilha) {
    cout << "Pilha: ";
    for (int i = 0; i < pilha.cont; i++) {
        cout << pilha.vector[i] << " ";
    }
    cout << "\n";
};

int main () {

    Pile pilha;
    bool ongoing = true;

    while (ongoing) {
        cout << "Escolha a funcionalidade:\n"
            << "(1) Empilhar\n"
            << "(2) Desempilhar\n"
            << "(3) Consultar topo\n"
            << "(4) Ver se a pilha esta vazia\n"
            << "(5) Sair\n";

        int option;
        cin >> option;

        switch (option) {
            case 1: {
                cout << "Insira o elemento a ser inserido: ";
                char element;
                cin >> element;
                if (stack(pilha, element)) cout << "Elemento inserido com sucesso!\n";
                else                       cout << "Erro!\n";
                print_pile(pilha);
                break;
            }

            case 2: {
                if (unstack(pilha)) cout << "Elemento deletado com sucesso!\n";
                else           cout << "Erro!";
                print_pile(pilha);
                break;
            }
            
            case 3: {
                cout << "Topo: " << top(pilha) << "\n";
                break;
            }

            case 4: {
                if (empty(pilha)) cout << "Pilha vazia!\n";
                else              cout << "Pilha nao vazia!\n";
                break;
            }

            case 5: {
                ongoing = false;
                break;
            }

            default: {
                cout << "Opcao invalida! Tente novamente.";
                break;
            }
        }   
    }

}
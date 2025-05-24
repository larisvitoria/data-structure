/*
Uma fila é um "tipo abstrato de dados (TAD)" (isto é, um padrão de uso de dados) no qual nós podemos:

- Criar uma fila vazia (isto é, uma coleção inicialmente sem elementos);
- Verificar se a fila está ou não vazia, em qualquer momento da sua utilização;
- Inserir um novo elemento (que pode inclusive ser igual a outro já inserido);
- Remover um elemento - no caso, o elemento removido será, necessariamente, aquele que foi inserido primeiro (dentre aqueles que não foram removidos ainda);
- Consultar o primeiro elemento, isto é, aquele que foi inserido primeiro, dentre aqueles que ainda não foram removidos (tanto na remoção quanto na consulta, o contexto básico de uso pressupõe que a fila não está vazia).

Nós começaremos estudando TADs limitados, ou seja, com um limite máximo para o número de elementos que poderão ser armazenados simultaneamente. No caso, uma fila limitada poderia ter o seguinte comportamento:

O número máximo de elementos poderia ser fixado estaticamente no código ou dinamicamente, no momento da criação da fila;
A fila poderia ter uma operação adicional para verificar se ela está ou não cheia;
A inserção somente insere o elemento recebido se a fila não estiver cheia (e pode retornar um booleano informando se a inserção aconteceu).
Pergunta: como implementar uma fila usando um vetor de tamanho fixo (digamos, 5), que permita uma quantidade ilimitada de operações, desde que o número máximo de elementos da fila nunca seja excedido?
*/

#include <iostream>

using namespace std;

// Constante usada para o tamanho do vetor
const int vector_size = 5;

struct Queue {
    // Vector guarda a estrutura de dados utilizada (vetor)
    char vector[vector_size];
    // F (first) guarda o index do primeiro elemento, iniciado como -1 indicando que a fila esta vazia
    int f = -1;
    // L (last) guarda o index do ultimo elemento, nao inicializado
    int l;
};

bool empty (Queue &Q) {
    // Definição que usamos para uma fila vazia
    return Q.f == -1;
}

bool full (Queue &Q) {
    // (Última posição + 1) Resto da divisão do tamanho do vetor == Primeira posição
    // Ex. [0, 1, 2, 3, 4]
    // 4 + 1 = 5 % 5 = 0.
    // Primeira posição ocupada?
    return (Q.l + 1) % vector_size == Q.f;
}

// Insere no final da fila
bool insert (Queue &Q, char element) {
    // Cheia
    if (full(Q)) return false;
    // Vazia
    if (Q.f == -1) {
        Q.f = Q.l = 0;
    }
    // Possui elementos
    else {
        Q.l = (Q.l + 1) % vector_size;
        // Ou
        // if (Q.l == vector_size - 1) Q.l = 0;
        // ++Q (Incrementa e atribui), Q++ (Atribui e incrementa)
        // else ++Q.l;
    }
    Q.vector[Q.l] = element;
    return true;
}

// Retorna o primeiro elemento
char first (Queue &Q) {
    return Q.vector[Q.f];
}

// Deleta o primeiro da fila
bool del (Queue &Q) {
    // Vazia
    if (Q.f == -1) return false;
    if (Q.f == Q.l) Q.f = -1;
    else            Q.f = (Q.f + 1) % vector_size;
    return true;
}

// Imprime a fila
void print_queue (Queue &Q) {
    // Quebrando em algum momento!
    int i = Q.f;
    while (i != (Q.l + 1) % vector_size) {
        cout << i << " " << Q.vector[i] << "\n";
        i = (i + 1) % vector_size;
    }
}

int main() {

    // Criando fila
    Queue fila;

    for (;;) {
        cout << "Escolha a funcionalidade:\n" << "(1) Inserir\n" << "(2) Deletar\n" << "(3) Primeiro\n" << "(4) Sair\n";
        int option;
        cin >> option;

        switch (option) {
            case 1:
                cout << "Insira o elemento: ";
                char element;
                cin >> element;
                if (insert(fila, element)) cout << "Elemento inserido com sucesso!\n";
                else                       cout << "Erro!";
                cout << "Fila atualizada:\n";
                print_queue(fila);
                break;

            case 2:
                if (del(fila)) cout << "Ultimo elemento deletado com sucesso!\n";
                else           cout << "Erro!";
                cout << "Fila atualizada:\n";
                print_queue(fila);
                break;
            
            case 3:
                cout << "Primeiro elemento: " << first(fila) << "\n";
                break;

            case 4:
                return 0;
                break;

            default:
                cout << "Opcao invalida! Tente novamente.";
                break;
            }
    }

}
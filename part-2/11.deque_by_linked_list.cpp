// Deque via lista encadeada

/*
# Descrição:
Deque (Double-Ended Queue): O deque é uma estrutura de dados que generaliza a fila, permitindo inserções e remoções em ambas as extremidades, também conhecidas como "esquerda" e "direita".

# Funcionamento:
- Inserção: Elementos podem ser adicionados tanto no início quanto no final do deque.
- Remoção: Elementos podem ser removidos tanto do início quanto do final do deque.

# Importância:
O deque mantém uma sequência única de elementos. Portanto, um elemento inserido em uma extremidade pode ser removido da outra extremidade, proporcionando flexibilidade adicional em comparação com as filas tradicionais.

# Aplicações:
- Algoritmos: Usado em algoritmos que requerem acesso rápido a ambos os extremos dos dados.
- Buffers: Utilizado em buffers de dados e sistemas de cache onde é necessário adicionar e remover dados de ambos os lados.
- Implementações: Pode ser implementado usando uma lista encadeada para gerenciar eficientemente as inserções e remoções em ambas as extremidades.
*/

#include <iostream>

using namespace std;

struct Deque ( // Declaração da estrutura do deque

    struct Node { // Declaração do nó com dupla referência
        Node *prev; // Nó à esquerda
        char element; // Elemento do nó
        Node *next; // Nó à direita
    }

    Node *left, *right // Nós à extremidade da esquerda e da direita do deque

    Deque() { // Construtor do deque
        left = right = nullptr; // Inicializando os ponteiros indicadores como nulos
    }
    
    bool empty() { // Função de retorno atual do deque (vazia = true, não vazia = false)
        return (if left == nullptr and right == nullptr); // O deque está vazio quando seus dois ponteiros indicadores são nulos
    }

    void push_left(char new_element) { // Insere à esquerda um novo elemento do deque
        Node *new_node_pointer = new Node(nullptr, new_element, left); // Instanciando um ponteiro que aponta para o novo nó alocado dinamicamente por meio da função new. Sua esquerda é definida como nula, equanto sua direita recebe o elemento da esquerda anterior
        if (left == nullptr) {right = new_node_pointer}; // Se "left" for nulo, ou seja, o deque é vazio, aponte o ponteiro da direita para o novo nó, dessa forma, teremos os dois ponteiros (left e right) apontando para o novo nó único no deque
        else                 {left -> prev = new_node_pointer;} // Caso não, acessamos o campo "prev" (previous) da esquerda anterior e substituímos pelo ponteiro do novo nó
        // (left == nullptr ? right : left -> prev) = new_node_pointer; Versão com operador ternário
        left = new_node_pointer; // O ponteiro da esquerda recebe o novo ponteiro
    }

    void push_right(char new_element) { // Mesma lógica do anterior, só que em relação à direita
        Node *new_node_pointer = new Node {right, new_element, nullptr};
        if (right == nullptr) {left = new_node_pointer;}
        else                  {right -> next = new_node_pointer;}
        right = new_node_pointer;
    }

    void delete_left() { // Função de deletar o elemento da esquerda do deque. Parte da pré-condição de que não está vazia
        Node *aux = left; // Ponteiro auxiliar ao nó da extremidade esquerda
        left = left -> prev; // Define a nova esquerda do deque, definindo o nó imediatamente anterior da antiga esquerda
        left -> next = nullptr; // Acessa a nova esquerda e remove a referência à esquerda anterior
        delete aux; // Deleta dinamicamente o dado apontado pelo ponteiro auxiliar (o delete consegue remover memória alocada dinamicamente com o new)
    }

)
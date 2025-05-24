// Fila via lista encadeada

/*
Uma fila é uma estrutura de dados que segue o princípio FIFO (First In, First Out), o que significa que o primeiro elemento adicionado é o primeiro a ser removido. Sua estrutura é semelhante a uma fila em um banco ou supermercado, onde as pessoas são atendidas na ordem em que chegaram.

# Estrutura de uma Fila
- Elementos: A fila armazena elementos em uma sequência linear. Cada elemento é inserido no final da fila e removido do início.

# Operações Principais:
- Enqueue: Adiciona um elemento ao final da fila.
- Dequeue: Remove e retorna o elemento do início da fila.
- Front: Retorna o elemento no início da fila sem removê-lo.
- IsEmpty: Verifica se a fila está vazia.

# Exemplos de uso:
- Fila de Impressão: Gerencia a ordem dos documentos a serem impressos em uma impressora.
- Gerenciamento de Tarefas: Organiza processos em sistemas operacionais para execução na ordem em que foram solicitados.
- Atendimento ao Cliente: Organiza chamadas ou solicitações de clientes para atendimento em ordem de chegada.
- Filas em Bancos/Supermercados: Ordena clientes para serem atendidos em caixas na ordem de chegada.
- Processamento em Redes: Garante que pacotes de dados sejam processados na ordem correta de recebimento.
- Busca em Largura (BFS): Explora vértices de um grafo em ordem, utilizando uma fila para gerenciar a descoberta dos vértices.
- Buffering de Dados: Armazena dados temporariamente em uma fila para garantir a reprodução contínua em sistemas de streaming.
*/

#include <iostream>

using namespace std;

struct Queue { // Define a estrutura de fila

    struct Node { // Define a estrutura do nó
        char element; // Elemento do nó
        Node *next; // Ponteiro do nó, aponta para o próximo nó
    };

    Node *first, *last;

    Queue() { // Construtor da fila
        first = last = nullptr; // Define o ponteiro de primeiro e último como nulos
    };

    void insert(char new_element) { // Enfileira o novo elemento no fim da fila
        Node *new_node_pointer = new Node{new_element, nullptr}; // Instancia um ponteiro que aponta para o novo nó, instanciado dinamicamente e seu valor next apontando para um campo nulo
        if (first == nullptr) first = new_node_pointer; // Se a fila estiver vazia, o novo nó será o primeiro da fila
        else last -> next = new_node_pointer; // Caso não, altere o campo "next" do último da fila, agora ele deve apontar para o novo nó
        // (first == nullptr? first : last -> next) = new_node_pointer
        last = new_node_pointer; // O ponteiro de último da fila agora aponta para o novo nó adicionado
    };

    void insert_first(char new_element) { // Enfileira um novo elemento no início da fila, parte da pré-condição de que a fila não está vazia
        Node *new_node_pointer = new Node{new_element, first}; // Instancia um ponteiro que aponta para o novo nó, que recebe em seu campo "next" o primeiro elemento anterior
        first = new_node_pointer; // O novo início será o novo nó
    }

    char unqueue() { // Remove e retorna o elemento do início da fila, parte da pré-condição de que a fila não está vazia
        Node *aux = first; // Cria um ponteiro auxiliar que aponta para o primeiro atual
        first = first -> next; // O novo primeiro será o próximo elemento, anterior ao antigo primeiro
        return aux -> element; // Retorna o elemento removido
        delete aux; // Delete a memória do nó dinamicamente
    };

    char front() { // Retorna o primeiro elemento da fila
        return first -> element;
    };

    bool empty() { // Retorna se a fila está vazia
        return first == nullptr; // Ocorre quando o primeiro elemento for nulo
    };

    void print() { // Imprime a fila
        Node *aux = first; // Ponteiro auxiliar que percorrerá a fila
        while (aux != nullptr) { // Enquanto o elemento da vez não for nulo (fim da fila)
            cout << aux -> element << " ";
            aux = aux -> next; // Atualiza o ponteiro auxiliar
        }
    };

    ~Queue() { // Destrutor
        while (not empty()) unqueue();
    };

};


int main() {

    Queue my_queue; // Instancia a fila

    for (;;) { // Loop infinito
        cout << "\n=== Escolha a funcionalidade: ===\n" << "(1) Inserir\n" << "(2) Deletar\n" << "(3) Consultar o primeiro\n" << "(4) Consultar se esta vazia\n" << "(5) Imprimir fila\n" << "(6) Inserir elemento no inicio\n" << "(7) Sair\n";
        int option;
        cin >> option;

        switch (option) {
            case 1:
                cout << "Insira o elemento: ";
                char element;
                cin >> element;
                my_queue.insert(element);
                cout << "Elemento inserido com sucesso!\n";
                break;

            case 2:
                my_queue.unqueue();
                cout << "Primeiro elemento desenfileirado com sucesso!\n";
                break;
            
            case 3:
                cout << "Primeiro elemento: " << my_queue.front() << "\n";
                break;
            
            case 4:
                if (my_queue.empty()) cout << "Fila vazia!\n";
                else                  cout << "Fila nao vazia!\n";
                break;

            case 5:
                cout << "Fila atual:\n";
                my_queue.print();
                break;

            case 6:
                cout << "Insira o elemento: ";
                char new_element;
                cin >> new_element;
                my_queue.insert_first(new_element);
                cout << "Elemento adicionado ao inicio com sucesso!\n";
                break;

            case 7:
                return 0;
                break;

            default:
                cout << "Opcao invalida! Tente novamente.";
                break;
            }
    }

}
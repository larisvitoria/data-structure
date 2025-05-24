// Pilha via lista encadeada

/*
Uma pilha (ou "stack", em inglês) é uma estrutura de dados fundamental que segue o princípio LIFO (Last In, First Out), ou seja, o último elemento a ser inserido é o primeiro a ser removido. É semelhante a uma pilha de pratos: você adiciona novos pratos no topo e também retira pratos do topo.

# Estrutura de uma Pilha
- Top (Topo): Aponta para o elemento no topo da pilha. É a única posição de acesso direto para inserção e remoção de elementos.
- Push: Operação para adicionar um novo elemento ao topo da pilha.
- Pop: Operação para remover o elemento do topo da pilha.
- Peek/Top: Operação para acessar o elemento no topo da pilha sem removê-lo.
- IsEmpty: Verifica se a pilha está vazia.

# Exemplo de Uso
As pilhas são usadas em muitas aplicações, como:

- Chamadas de Função: O rastreamento das chamadas de função e variáveis locais.
- Desfazer e Refazer: Funcionalidade de desfazer e refazer em editores de texto.
- Algoritmos: Algoritmos como a conversão de expressões infixas para pós-fixas e a resolução de problemas de balanceamento de parênteses.
*/

#include <iostream>

using namespace std;

struct Stack { // Definição da pilha

    struct Node { // Definição do nó, estrutura interna à pilha
        char element; // Elemento do nó
        Node *next; // Ponteiro para o próximo ponto da pilha (que no caso, será o nó imediatamente anterior)
    };

    Node *top = nullptr; // Declara o ponteiro "top" como atributo da struct

    Stack() { // Construtor da pilha
        top = nullptr; // Definição do primeiro elemento da lista como nulo. Será futuramente utilizado como ponteiro que referencia o nó no topo da pilha
    }

    void push(char new_element) { // Empilha um elemento
        /*
        1. Cria o novo nó: Node *new = new Node;
        2. Atribui o elemento ao novo nó: new -> element = new_element;
        3. Ao ponteiro de próximo do novo nó, atribui o topo anterior da pilha: new -> next = top;
        4. Define o novo topo como o novo nó criado: top = new;
        */

        top = new Node {new_element, top}; // Define o atributo de topo como um novo nó com o novo elemento, referenciando o topo anterior, fazendo assim, com que tenhamos acesso ao item imediatamente interior ao topo
        // A função new é usada para alocar memória dinamicamente para um objeto ou variável e inicializá-lo
    }

    char peek() { // Retorna o elemento no topo da pilha, parte da pré-condição de que a pilha não está vazia
        return top -> element; // Acessa o campo de elemento do nó referenciado pelo ponteiro "top"
    }

    void pop() { // Desempilha um elemento, parte da pré-condição de que a pilha não está vazia
        Node *aux = top; // Cria um ponteiro auxiliar que aponta para o topo atual
        top = top -> next; // O topo da pilha recebe o elemento anterior, acessando-o por meio do campo "next" do ponteiro "top"
        delete aux; // Apaga a memória do topo anterior por meio de um ponteiro auxiliar
        
        // A função delete é usada para desalocar memória que foi previamente alocada
    }   

    bool empty() { // Checa se a pilha está vazia
        return (top == nullptr); // Retorna o valor da condição em booleano, indicando "true" para vazia e "false" para não vazia
    }

    void print() { // Imprime a pilha no console, parte da pré-condição de que não está vazia
        Node *aux = top; // Ponteiro auxiliar que inicialmente aponta para o topo da pilha 
        while (aux != nullptr) { // Enquanto o elemento analisado não for nulo:
            cout << aux -> element << " "; // Imprima o elemento do nó analisado
            aux = aux -> next; // Atribua um novo valor (o nó anterior) ao ponteiro auxiliar
        }
    }

    ~Stack() { // Destrutor da pilha
        while (not empty()) pop(); // Enquanto ela não estiver vazia, desempilhe
    }

};

int main() {

    Stack my_stack; // Instancia a pilha

    for (;;) { // Loop infinito
        cout << "\n=== Escolha a funcionalidade: ===" << "(1) Inserir\n" << "(2) Deletar\n" << "(3) Consultar topo\n" << "(4) Consultar se esta vazia\n" << "(5) Imprimir pilha\n" << "(6) Sair\n";
        int option;
        cin >> option;

        switch (option) {
            case 1:
                cout << "Insira o elemento: ";
                char element;
                cin >> element;
                my_stack.push(element);
                cout << "Elemento inserido com sucesso!\n";
                break;

            case 2:
                my_stack.pop();
                cout << "Elemento do topo deletado com sucesso!\n";
                break;
            
            case 3:
                cout << "Primeiro elemento: " << my_stack.peek() << "\n";
                break;
            
            case 4:
                if (my_stack.empty()) cout << "Pilha vazia!\n";
                else                  cout << "Pilha nao vazia!\n";
                break;

            case 5:
                cout << "Pilha atual:\n";
                my_stack.print();
                break;

            case 6:
                return 0;
                break;

            default:
                cout << "Opcao invalida! Tente novamente.";
                break;
            }
    }

}
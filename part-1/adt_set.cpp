/* Exercícios para Casa da Aula 04:

- Implemente em C++ um conjunto limitado via vetor ordenado, utilizando na função "pertence"
o algoritmo de busca binária discutido em sala. Inclua as funções vazio e cheio.
Escreva uma versão recursiva do algoritmo de busca binária.

Escreva uma variação do algoritmo de busca binária que, ao invés de informar se o elemento "x"
está ou não presente, informe a posição em que o elemento deveria ser inserido; essa posição é
aquela imediatamente após o último dos elementos menores que "x" (caso haja; se não houver nenhum
menor, a posição é zero). Naturalmente, essa versão alternativa do algoritmo não tem como propósito
ser usada na função "pertence" de uma implementação de conjunto; no caso, o intuito seria aproveitá-la
para realizar uma versão um pouco mais eficiente da função de inserção, que usaria busca binária no lugar
de busca linear para descobrir o local onde o elemento deve ser inserido.*/

#include <iostream>

using namespace std;

// Declarando a constante global que armazena o tamanho do vetor
const int vector_size = 10;

/* Implemente em C++ um conjunto limitado via vetor desordenado, conforme explicado em sala,
com particular atenção ao procedimento de remoção (não realizando deslocamento dos elementos
à direita do elemento removido). Inclua uma função vazio, que informe se o conjunto está ou não
vazio. Inclua também uma função cheio, que informe se o conjunto está ou não cheio. Os valores
devem ser únicos */
// Declarando um conjunto limitado via vetor desordenado
class UnorderedSet {

    // Membros privados
    private:
        int f = 0; // Index da primeira posição ocupada (first)
        int l = 0; // Index da última posição ocupada (last)
        int n = 0; // Número de elementos adicionados ao vetor

    // Membros públicos
    public:
        // Construtor
        UnorderedSet();
        char vector[vector_size]; // Vetor

        bool add(char element, UnorderedSet &set) {
            // Roda se não estiver cheia e o elemento não existir no conjunto
            if (not set.n == vector_size - 1 && not set.is_element(element)) {
                // Próximo espaço vago na lista é no começo?
                set.l = (set.l + 1) % vector_size;
                // Adiciona o elemento no vetor do objeto set
                set.vector[l] = element;
                // Incrementa o número de elementos adicionados ao vetor
                n++;
                // Retorna o caso bem sucedido
                return true;
            }
            return false;
        }

        bool remove(char element, UnorderedSet &set) {
            if (not set.is_empty()) {
                return false;
            }

            // Diminui a quantidade de elementos
            set.n -= 1;
        };

        bool is_empty() {
            return f == l;
        };

        // Busca linear no vetor
        bool is_element(char element, UnorderedSet &set) {
            for (int i = 0; i <= vector_size; i++) {
                if (set.vector[i] == element) {
                    return true;
                }
            }
            return false;
        };
};

void main() {

};

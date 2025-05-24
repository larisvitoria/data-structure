// Aula 13: Matrizes

#include <iostream>
#include <exception>

using namespace std;

class Matrix {
    private:
    int m_rows; // Número de linhas
    int n_columns; // Número de colunas
    // **: Representa um ponteiro para ponteiro
    // Esse ponteiro irá guardar o endereço da matriz, que é formada por vetores (essencialmente ponteiros)
    double **M;

    public:
    // Construtor da matriz
    Matrix(int rows, int columns) {
        // Define os valores internos da matriz
        m_rows = rows;
        n_columns = columns;

        // Instancia um vetor inicial dinamicamente (o valor só será conhecido após a compilação do código)
        M = new double* [m_rows];
        // Loop que itera sobre as linhas da matriz, formando novos vetores que representam as colunas da matriz
        // Primeiro ele incrementa o iterador e depois realizada a ação definida
        for (int r = 0; r < m_rows; r++) {
            M[r] = new double [n_columns];
            // Ou: *(M + r) = new double* [n_columns];
        }

        // Envolver o código em um bloco de try-catch para evitar erros
    }

    // Destrutor da matriz
    ~Matrix() {
        // Itera sobre as linhas da matriz
        for (int d = 0; d < m_rows; d++) {
            // Delete a memória alocada dinamicamente de cada coluna associada à linha analisada
            delete[] M[d];
        }
        // Deleta o vetor que representa as linhas da matriz
        delete[] M;
    }

    // Atribui um valor à uma posição dentro da matriz
    // void set_value(double element, int row, int column) {M[row][column] = element;}

    // Retorna o valor associado à uma certa posição dentro da matriz
    // double return_value(int row, int column) {return M[row][column];}

    // Acessa o ponteiro daquele elemento
    // double* return_pointer(int row, int column) {return &M[row][column];}

    // Acessa a referência daquele elemento
    // double& return_reference(int row, int column) {return M[row][column];}

    // É uma forma de acessar a referência de um elemento dentro da matriz, dessa forma, você pode acessá-lo por meio de parênteses, como uma função. Permite substituir todas as outras funções anteriores.
    // Referência: Permite acessar um elemento e alterá-lo diretamente por meio de uma outra variável que não pode ser reapontada
    // Exemplo: matriz(linha, coluna)
    double& operator() (int row, int column) {return M[row][column];}

    // Imprime a matriz no terminal
    void print_matrix() {
        // Loop que itera sobre as colunas da matriz
        for (int i = 0; i < m_rows; i++) {
            // Loop que itera sobre as linhas da matriz
            for (int j = 0; j < n_columns; j++) {
                // Imprime o elemento atual
                cout << "[" << M[i][j] << "] ";
                if (i == n_columns - 1) cout << "\n";
            }
        }
    }
};

int main() {

    try {

        cout << "=== Estrutura de dados: Matriz ===\n";

        int linhas; cout << "Linhas: "; cin >> linhas;
        int colunas; cout << "Colunas: "; cin >> colunas;

        Matrix matriz(linhas, colunas);

        for (;;) {
            cout << "\n=== Escolha a funcionalidade: ===\n" <<
            "(1) Definir valor\n" <<
            "(2) Retornar elemento\n" <<
            "(3) Imprimir matriz\n" <<
            "(4) Deletar matriz\n" <<
            "(5) Sair\n";

            int option;
            cin >> option;

            switch (option) {
                case 1: {
                    double elemento; cout << "Insira o valor: "; cin >> elemento;
                    int linha; cout << "Insira a linha: "; cin >> linha;
                    int coluna; cout << "Insira a coluna: "; cin >> coluna;
                    matriz(linha, coluna) = elemento;
                    cout << "Novo valor definido com sucesso!\n";
                    break;
                }

                case 2: {
                    int linha; cout << "Insira a linha: "; cin >> linha;
                    int coluna; cout << "Insira a coluna: "; cin >> coluna;
                    cout << "Elemento: " << matriz(linha, coluna);
                    break;
                }

                case 3:
                    cout << "Matriz atual: \n";
                    matriz.print_matrix();
                    break;
                
                /* case 4:
                    delete matriz;
                    cout << "Matriz deletada com sucesso.\n";
                    break; */

                case 5:
                    return 0;
                    break;

                default:
                    cout << "Opcao invalida! Tente novamente.";
                    break;
            }
        }
    }

    // Captura e imprime o erro, finalizando o programa
    catch (const exception &e) {
        cerr << "Excecao capturada: " << e.what() << "\n";
        return 1;
    }
}

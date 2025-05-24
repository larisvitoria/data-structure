// Implementação de um dicionário limitado via vetor (estrutura abstrata de dados)

/* Definição: 
Contêiner com pelo menos as seguintes operações:
    a) Inserir (c, v): Insere a chave "c" e o valor "v" (há diferentes alternativas para
    quando já há um valor correspondente a "c" no dicionário)
    b) Consultar (c): Retorna o valor correspondente à chave "c", ou informa que não há
    tal valor
    c) Remover (c): Remove do dicionário a chave "c" e o valor a ela correspondente, caso
    haja
Observações:
    - Em um dicionário, ou uma chave "c" não está presente ou ela está presente e existe
    exatamente um valor a ela correspondente e armazenado.
    - Não há repetição de chaves, nem há multiplos valores associados à uma chave, ela é única (ID).
    - Mas, não há problema em chaves diferentes estarem associadas a valores iguais.
    - Em ambas as alternativas, é possível manter as chaves ordenadas ou desordenadas entre si,
    o que deve ser avaliado é a situação, pois em um caso desordenado temos ganho na rapidez de remoção
    e inserção de elementos, enquanto perdemos na busca. Já no caso ordenado, temos ganho na busca e perda
    na inserção e remoção (parcialmente, por conta da busca binária).
    - A chave não necessariamente precisa ser igual ao index do vetor.
*/

#include <iostream>
#include <string>

using namespace std;

/* 2° forma (ORDENADO):
Usando um vetor de struct's.
*/

const int dict_size = 5;

struct Element {
    int key;
    string value;
}

Element create_element(int setkey, string setvalue) {
    Element new_element;
    cin >> setkey;
    new_element.key = setkey;
    getline(cin, setvalue);
    new_element.value = setvalue;
    return new_element;
}

// Dicionario
struct Dict2 {
    // Vetor
    Element vetor[dict_size];
    // Inteiro que guarda a quantidade de elementos presentes
    int cont = 0;
};

// Função de inserção
bool insert(Dict2 &dict, int key, string value) {
    // Checamos se há espaço
    if (dict.cont == dict_size) return false;
    // Checamos se já existe a chave
    // Busca binária se não for vazia
    if (dict.cont != 0) {
        // Início (First) = 0
        int f = 0;
        // Final (Last) = última posição ocupada
        int l = dict.cont - 1;
        // Enquanto o último for maior que o primeiro
        while (l > f) {
            // Meio atualizado com base em f e l
            int m = i + (f - i) / 2;
            if (m == key) {
                // Se tudo ok, insira
                /* dict.keys[dict.cont] = key;
                dict.values[dict.cont] = value;
                dict.cont++; */
                return true;
            }
            else if (m > key) {
                f = m - 1;
            }
            else {
                i = m + 1;
            }
        }
    }
    return false;
};

// Função de busca de valor por chave
string search(Dict1 &dict, int key) {
    // Checamos se o conjunto está vazio
    // if (dict.cont == 0) {
    //     return "Error";
    // }
    // Checamos se a chave existe, se sim, retorna o valor
    for (int i = 0; i < dict.cont; i++) {
        if (dict.keys[i] == key) return dict.values[i];
    }
    return "Error";
};

// Função de remoção
bool remove(Dict1 &dict, int key) {
    // Como a estrutura é desordenada, iremos realocar o último elemento
    // para preencher o vazio causado pela remoção
    // Checamos se a chave existe (pode ser feito uma função para checagem)
    for (int i = 0; i < dict.cont; i++) {
        // Se achar
        if (dict.keys[i] == key) {
            // Existem duas possibilidades: está no final do dicionário ou no meio
            // O processo é o mesmo se estiver no final ou no meio, mas por questão
            // de otimização, faremos uma validação
            // Pega o útlimo elemento e coloque no lugar
            if (i != dict.cont - 1) {
                dict.keys[i] = dict.keys[dict.cont-1];
                dict.values[i] = dict.values[dict.cont-1];
            }
            // Deu certo
            dict.cont--;
            return true;
        }
    }
    return false;
}

void print_dict(Dict1 &dict) {
    for (int i = 0; i < dict.cont; i++) {
        cout << "Key: " << dict.keys[i] << " / Value: " << dict.values[i] << "\n";
    }
}

int main () {

    Dict1 dict;
    bool ongoing = true;

    while (ongoing) {
        cout << "Escolha a funcionalidade:\n"
            << "(1) Inserir\n"
            << "(2) Deletar\n"
            << "(3) Buscar\n"
            << "(4) Sair\n";

        int option, key;
        string value;
        cin >> option;

        switch (option) {
            case 1: {
                cout << "Insira a chave do elemento: ";
                cin >> key;
                cout << "Insira o valor do elemento: ";
                // Função usada para ignorar o que vai ser escrito no cin anterior
                cin.ignore();
                getline(cin, value);
                if (insert(dict, key, value)) cout << "Elemento inserido com sucesso!\n";
                else                       cout << "Erro!\n";
                cout << "Dicionario atualizado:\n";
                print_dict(dict);
                break;
            }

            case 2: {
                cout << "Insira a chave do elemento: ";
                cin >> key;
                if (remove(dict, key)) cout << "Elemento deletado com sucesso!\n";
                else           cout << "Erro!";
                cout << "Dicionário atualizada:\n";
                print_dict(dict);
                break;
            }
            
            case 3: {
                cout << "Insira a chave do elemento: ";
                cin >> key;
                cout << "Valor do elemento: " << search(dict, key) << "\n";
                break;
            }

            case 4: {
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
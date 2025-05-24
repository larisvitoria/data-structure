#include <iostream>
#include <new>

using namespace std;

struct Deque {

    struct Noh {
        Noh *anterior;
        int elemento;
        Noh *proximo;
    };

    Noh *esquerda_do_dq, *direita_do_dq;

    Deque() {
        esquerda_do_dq = direita_do_dq = nullptr;
    }

    bool vazio() {
        return (esquerda_do_dq == nullptr and direita_do_dq == nullptr);
    }

    void inserir_a_esquerda(int valor) {
        Noh *novo_noh = new Noh{nullptr, valor, esquerda_do_dq};
        if (vazio()) {direita_do_dq = novo_noh;}
        else {esquerda_do_dq -> anterior = novo_noh;};
        esquerda_do_dq = novo_noh;
    }

    void inserir_a_direita(int valor) {
        Noh *novo_noh = new Noh{direita_do_dq, valor, nullptr};
        if (vazio()) {esquerda_do_dq = novo_noh;}
        else {direita_do_dq -> proximo = novo_noh;};
        direita_do_dq = novo_noh;
    }

    void deletar_esquerda() { // Pré-condição: não está vazio
        Noh *aux = esquerda_do_dq;

        esquerda_do_dq = esquerda_do_dq -> proximo;

        if (esquerda_do_dq == nullptr) {direita_do_dq = nullptr;}
        else {esquerda_do_dq -> anterior = nullptr;};
        delete aux;
    }

    void deletar_direita() {
        Noh *aux = direita_do_dq;
        direita_do_dq = direita_do_dq -> anterior;
        if (direita_do_dq == nullptr) {esquerda_do_dq = nullptr;}
        else {direita_do_dq -> proximo = nullptr;};
        delete aux;
    }

    int consultar_esq() {
        return esquerda_do_dq -> elemento;
    }

    int consultar_direita() {
        return direita_do_dq -> elemento;
    }

    ~Deque() {
        while(esquerda_do_dq != nullptr) {
            deletar_esquerda();
        }
    }

};

int main() {

    Deque meu_deque;

    for (;;) {
        cout << "Escolha a funcionalidade:\n"
            << "(1) Inserir a esquerda\n"
            << "(2) Inserir a direita\n"
            << "(3) Remover a esquerda\n"
            << "(4) Remover a direita\n"
            << "(5) Consultar a esquerda\n"
            << "(6) Consultar a direita\n"
            << "(7) Deque vazio\n"
            << "(8) Deletar deque\n";

        int option;
        cin >> option;

        switch (option) {
            case 1:
                cout << "Insira o elemento: ";
                int x;
                cin >> x;
                meu_deque.inserir_a_esquerda(x);
                break;

            case 2:
                cout << "Insira o elemento: ";
                int y;
                cin >> y;
                meu_deque.inserir_a_direita(y);
                break;
            
            case 3:
                meu_deque.deletar_esquerda();
                break;

            case 4:
                meu_deque.deletar_direita();
                break;

            case 5:
                cout << meu_deque.consultar_esq() << endl;
                break;

            case 6:
                cout << meu_deque.consultar_direita() << endl;
                break;

            case 7:
                if (meu_deque.vazio()) {cout << "Vazio!\n";}
                else {cout << "Nao vazio!\n";};
                break;
            
            case 8:
                meu_deque.~Deque();
                break;

            default:
                cout << "Opcao invalida! Tente novamente.";
                break;
        }

    }
}
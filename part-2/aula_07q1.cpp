/*
Exercícios da Aula 07:

Escreva uma implementação de pilha ilimitada, no sentido de que ela não deve possuir um limite conhecido a priori para o número de elementos passíveis de nela serem armazenados. Ao invés de um vetor de tamanho fixo, a "struct" deve possuir um ponteiro que, durante a execução da função de inicialização, deve receber um pequeno vetor alocado dinamicamente. Sempre que a função "empilhar" encontrar o vetor cheio, ela deve (1) alocar um vetor maior, (2) copiar para ele os elementos da pilha, (3) desalocar o vetor atual e (4) passar a utilizar o vetor maior como o vetor da pilha.
(Opcional) Com base na sintaxe ilustrada no programa abaixo para templates, reescreva a sua implementação de pilha do programa da questão anterior de forma que ela seja genérica quanto ao tipo. Em seguida, teste a sua implementação, criando e utilizando pilhas de diferentes tipos.
 
// --------------------------------------------------------------
// O intuito deste código é apenas ilustrar a definição
// de tipos e funções polimórficas.
// As funções em questão, em si mesmas, seriam dispensáveis,
// pois seria mais simples escrever, por exemplo,
// "p.x" ao invés de "primeiro(p)";
// mesmo assim, porém, as funções ilustram a sintaxe dos
// "templates", que é o objetivo.


#include <iostream>
using namespace std;

template <typename TX, typename TY>
struct Par
  {
   TX x;
   TY y;
  };

template <typename TX, typename TY>
TX primeiro (Par<TX,TY> p)
  {
   return p.x;
  }


template <typename A, typename B>
B segundo (Par<A,B> p)
  {
   return p.y;
  }

int main ()
  {
   Par<double,char> p {3.14, '!'};

   cout << "{ " << primeiro (p) << ", " << segundo (p) << " }\n";

   Par <int, Par<double,char> > q { 10, p };

   cout << primeiro(segundo(q)) << '\n';
  }

// --------------------------------------------------------------

---

*/

#include <iostream>

using namespace std;

struct PilhaIlimitada {

    int n = 2;
    int *topo;

    PilhaIlimitada() {
        int *v = new int[n];
        topo = nullptr;
    }

    void empilhar(int elemento) {
        
    }

    ~PilhaIlimitada() {

    }

}

int main() {



}
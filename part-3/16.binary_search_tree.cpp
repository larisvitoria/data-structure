#include <iostream>

using namespace std;

class BinarySearchTree{

    private:
    struct Node{
        Node *left;
        int element;
        Node *right;
    };

    public:
    Node *root;

    BinarySearchTree() {
        root = nullptr;
    }

    void deleteTree(Node* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    bool empty() {
        return (root == nullptr);
    }

    Node* BST_by_array(int *array, int begin, int end) {
        if (begin > end) {
            return nullptr; // Na última folha, retorne nulo
        }        

        int middle = (begin + end) / 2; // Posição no array
        Node *new_node = insert(array[middle]); // Insira o novo nó na árvore
        // E reatribua seus filhos por meio dessas chamadas recursivas
        new_node -> left = BST_by_array(array, begin, middle - 1);
        new_node -> right = BST_by_array(array, middle + 1, end);
        
        return new_node;
    }

    void print_tree(Node* tree_root) {
        if (tree_root == nullptr) return;
        print_tree(tree_root->left);   // Primeiro imprime os nós da subárvore esquerda
        cout << tree_root -> element << " ";
        print_tree(tree_root->right);  // Finalmente imprime os nós da subárvore direita
    }

    Node* search(int searching_elem) {
        Node *aux = root;

        while (aux != nullptr) {
            if (aux -> element > searching_elem) aux = aux -> left;
            else if (aux -> element < searching_elem) aux = aux -> right;
            else return aux;
        };

        return nullptr;
    }

    Node* insert(int new_elem) { // Pré-condição: o novo elemento não existe na árvore
        Node *new_node = new Node{nullptr, new_elem, nullptr};

        if (root == nullptr) { // Primeiro nó
            root = new_node;
            return new_node;
        }
        
        Node *aux = root;

        while (true) {

            if (new_elem < aux -> element) {
                if (aux -> left == nullptr) {
                    aux -> left = new_node;
                    return new_node;
                };
                aux = aux -> left;
            }

            else {
                if (aux -> right == nullptr) {
                    aux -> right = new_node;
                    return new_node;
                };
                aux = aux -> right;
            };
        };
    }

    Node* insert_if_new(int new_elem) {
        Node *new_node = new Node{nullptr, new_elem, nullptr};

        if (root == nullptr) { // Primeiro nó
            root = new_node;
            return new_node;
        }
        
        Node *aux = root;

        while (true) {

            if (new_elem < aux -> element) {
                if (aux -> left == nullptr) {
                    aux -> left = new_node;
                    return new_node;
                };
                aux = aux -> left;
            }

            else if (new_elem > aux -> element) {
                if (aux -> right == nullptr) {
                    aux -> right = new_node;
                    return new_node;
                };
                aux = aux -> right;
            };

            else { // O número já existe
                return nullptr;
            }
        };
    }

    bool delete (int removing_elem) {
        Node *parent = nullptr;
        Node *aux = root;

        while(aux != nullptr) {
            if (removing_elem < aux -> element) {
                parent = aux;
                aux = aux -> left;
            }
            else if (removing_elem > aux -> element) {
                parent = aux;
                aux = aux -> right;
            else break;
        }
        
        if (aux == nullptr) return false; // O elemento não pertence

        else { // Encontrou o nó
                
                // Não tem filhos
                if (aux -> left == nullptr and aux -> right == nullptr) {
                    if (root == aux) root = nullptr; // Se o nó deletado for a raiz
                    else if (parent -> left == aux) parent -> left = nullptr; // É filho esquerdo de seu pai? Se sim, reaponte o left do pai para nulo
                    else if (parent -> right == aux) parent -> right = nullptr; // É filho direito de seu pai? Se sim, reaponte o right do pai para nulo
                }

                // Tem apenas um filho direito
                else if (aux -> left == nullptr && aux -> right != nullptr) {
                    if (aux == root) root = aux -> right; // O nó deletado é a raiz
                    else if (parent -> left == aux) parent -> left = (aux -> right); // É filho esquerdo de seu pai? Se sim, reaponte o left do seu pai para o neto direito dele
                    else if (parent -> right == aux) parent -> right = (aux -> right); // É filho direito de seu pai? Se sim, reaponte o right do seu pai para o neto direito dele
                }

                // Tem apenas um filho esquerdo
                else if (aux -> right == nullptr && aux -> left != nullptr) {
                    if (aux == root) root = aux -> left; // O nó deletado é a raiz
                    else if (parent -> left == aux) parent -> left = (aux -> left); // É filho esquerdo de seu pai? Se sim, reaponte o left do seu pai para o neto esquerdo dele
                    else if (parent -> right == aux) parent -> right = (aux -> left); // É filho direito de seu pai? Se sim, reaponte o right do seu pai para o neto esquerdo dele
                }

                // Tem os dois filhos
                else if (aux -> right != nullptr && aux -> left != nullptr) { // Sabemos que ele terá dois filhos quando o seu filho direito e esquerdo não forem nulos

                    // Definimos um nó auxiliar que armazenará o menor valor (nó mais à esquerda) da sub-árvore direita
                    // A busca será feita por um loop, então ele já deve iniciar apontando para o filho direito do nó analisado, guiando a busca na subárvore direita do nó
                    Node* min_value = aux -> right; 

                    // Definimos outro nó auxiliar que irá armazenar o pai do nó com menor valor, isso vai ajudar nos reapontamentos da remoção
                    Node* parent_min_value = aux;

                    // Enquanto o filho esquerdo do nó analisado for diferente de nulo (quando for nulo, não existe mais nenhum valor menor do que o atual)...
                    while (min_value -> left != nullptr) {
                        // ...busque o menor nó (nó mais à esquerda na sub-árvore direita) percorrendo a árvore
                        // Na atualização de ponteiros o pai do nó analisado se torna ele mesmo...
                        parent_min_value = min_value;
                        // ...e o nó analisado se torna o seu filho esquerdo
                        min_value = min_value -> left;
                    }
                    // Ao fim desse loop, teremos o nó de menor valor e o seu pai

                    if (aux == root) root = min_value; // Se o nó a ser deletado (aux) for a raiz, o nó de menor valor (encontrado no loop anterior) vai assumir o papel de raiz

                    // Caso não seja a raiz, ele terá um pai (usaremos o ponteiro auxiliar do pai, calculado no início da função)
                    else if (parent -> left == aux) parent -> left min_value; // Se for o filho esquerdo de seu pai, atribua o novo filho esquerdo do pai em questão para o nó de menor valor encontrado anteriormente

                    else if (parent -> right == aux) parent -> right = (aux -> left); // Se for o filho direito, atribua o novo filho direito do pai em questão para o nó de menor valor encontrado anteriormente

                    // Se o pai do menor valor da sub-árvore direita de aux não for aux, ou seja, o nó a ser deletado tem netos e o menor valor tem um filho direito
                    if (parent_min_value != aux) {
                        // Reatribua ao filho esquerdo do pai do menor valor o filho direito do menor valor (ele só pode ter filho direito, pois se tiver um filho esquerdo significa que existe um nó com menor valor do que ele)
                        parent_min_value -> left = min_value -> right;
                        // O filho direito do menor valor vai se tornar o antigo filho direito de aux, no caso, pai de min_value
                        min_value -> right = aux -> right;
                        // Também poderia ser min_value -> min_value -> right = parent_min_value
                    }

                    // Caso não tenha bisnetos, apenas substitua
                    // Mas se tiver bisnetos, faça o passo anterior e esse também!
                    // O filho esquerdo no nó de menor valor, agora já alocado no lugar de aux (nó deletado), será o antigo filho esquerdo de aux
                    min_value -> left = aux -> left;
                }

                delete aux;
                return true;
            }
        }
    }

    int height(Node *analysed_node) {
        if (analysed_node == nullptr) return 0;

        int left_height = height(analysed_node -> left);
        int right_height = height(analysed_node -> right);

        return 1 + (left_height > right_height ? left_height : right_height);
    }

    bool is_it_avl(Node *analysed_node) {

        if (analysed_node == nullptr) return true;

        int left_height = height(analysed_node -> left);
        int right_height = height(analysed_node -> right);
        int diff = left_height - right_height;
        diff = diff > 0 ? diff : -diff;

        if diff > 1 return false;

        return is_it_avl(analysed_node -> left) && is_it_avl(analysed_node -> right);
    }

    ~BinarySearchTree() {
        deleteTree(root);
    }

};

int main() {

    BinarySearchTree testing_tree;

    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 10};
    try {
        testing_tree.root = testing_tree.BST_by_array(array, 0, 7);
    }
    catch (const bad_alloc& e) {
        cerr << "Falha ao alocar memoria na main: " << e.what() << endl;
    }
    testing_tree.insert(8);
    testing_tree.insert(9);
    testing_tree.insert(10);
    testing_tree.print_tree(testing_tree.root);

}
# **Estruturas de Dados**

## **Aula 17: Tabelas de Dispersão**

### **Estrutura de Tabela de Dispersão**

Uma **tabela de dispersão** (ou **tabela hash**) é uma estrutura de dados usada para armazenar e acessar dados de forma eficiente, com base em uma função hash que mapeia chaves para índices de uma tabela. É uma estrutura fundamental para implementar tabelas de símbolos e bancos de dados de forma rápida e eficiente. 

#### Componentes de uma Tabela de Dispersão:
- **Tabela**: Um array ou lista onde os elementos são armazenados.
- **Função Hash**: Uma função que mapeia uma chave para um índice na tabela.
- **Buckets**: As posições na tabela onde os dados são armazenados. Cada bucket pode armazenar uma lista de elementos em caso de colisões.

#### Propriedades de uma Tabela de Dispersão:
- **Chave**: Um identificador único para acessar os dados.
- **Índice**: A posição na tabela onde o valor correspondente à chave será armazenado.
- **Colisão**: O caso em que duas chaves são mapeadas para o mesmo índice. 

#### Aplicações de Tabelas de Dispersão:
1. **Armazenamento de Dados**: Armazenar e acessar dados rapidamente usando chaves únicas.
2. **Implementação de Conjuntos e Dicionários**: Utilizadas para criar conjuntos (collections) e dicionários (maps) que suportam inserções, buscas e remoções rápidas.
3. **Caches**: Armazenar resultados de cálculos ou consultas para acesso rápido.

#### Funcionamento da Tabela de Dispersão:
- **Inserção**: A chave é passada pela função hash para determinar o índice onde o valor será armazenado.
- **Busca**: A chave é novamente processada pela função hash para localizar o índice e recuperar o valor correspondente.
- **Remoção**: Similar à busca, mas remove o valor do índice determinado pela função hash.

#### Função Hash:
- **Objetivo**: Converter uma chave (que pode ser uma string, número, etc.) em um índice que será usado na tabela.
- **Propriedades Desejadas**:
  - **Distribuição Uniforme**: A função deve distribuir as chaves de forma uniforme para minimizar colisões.
  - **Determinística**: A mesma chave sempre deve mapear para o mesmo índice.

#### Tratamento de Colisões:
1. **Encadeamento**: Utiliza listas vinculadas (ou outras estruturas) para armazenar múltiplos elementos que colidirem no mesmo índice.
2. **Endereçamento Abertos**:
   - **Linear Probing**: Encontra o próximo índice disponível linearmente.
   - **Quadratic Probing**: Usa uma fórmula quadrática para encontrar o próximo índice disponível.
   - **Double Hashing**: Usa uma segunda função hash para calcular o próximo índice.

#### Exemplo de Tabela de Dispersão:
![Exemplo de Tabela de Dispersão](assets/image-11.png)

#### Operações em uma Tabela de Dispersão:
- **Inserção**: Calcula o índice da chave e armazena o valor no bucket correspondente.
- **Busca**: Calcula o índice da chave e acessa o bucket para encontrar o valor.
- **Remoção**: Calcula o índice da chave e remove o valor do bucket correspondente.

#### Eficiência:
- **Tempo Médio de Operação**: O tempo de busca, inserção e remoção é O(1) no caso ideal, mas pode se degradar para O(n) em casos de muitas colisões.
- **Espaço**: O espaço utilizado é proporcional ao número de buckets e o tamanho das listas de colisão.

#### Considerações:
- **Dimensionamento**: O tamanho da tabela deve ser escolhido adequadamente para minimizar colisões e manter a eficiência das operações.
- **Função Hash**: A escolha de uma boa função hash é crucial para o desempenho da tabela de dispersão.

![alt text](assets/image-12.png)

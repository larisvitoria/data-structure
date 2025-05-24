// Aula 10: Listas Encadeadas

/*
1. O vetor é uma estrutura de dados com muitas vantagens, como:
    a) Permitir um percurso sequencial eficiente;
    b) É eficiente no uso do espaço, quando o tamanho do vetor é próximo do número de elementos armazenados.
    
Entretanto, o vetor também possui desvantagens, quando utilizados como estruturas de dados dinâmicas, pois:
    a) Obrigam os elementos a mudar de localização na memória, no mínimo dificultando "referências" fixas;
    b) Levam as operações de redimensionamento a serem mais caras que as demais*, o que é um problema em aplicações onde nenhuma operação pode ser muito demorada.
    *: Existem alternativas que contornam esse problema, ao custo de tornar todas as operações menos eficientes.

2. A alternativa básica e clássica é a lista encadeada, cujas características básicas são:
    a) Os elementos não mudam de lugar na memória;
    b) Ponteiros são utilizados para "encadear os elementos"
*/
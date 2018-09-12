# teoria-grafos
Repositório do trabalho da disciplina Teoria dos Grafos 2018.2

O código em "métricas.cpp" ainda não foi atualizado. Por enquanto apenas a busca em largura foi atualizada. As buscas agora estão na classe Graph, que é pai das classes AdjacencyMatrix e AdjacencyList. Ambas as classes utilizam as buscas implementadas na classe mãe (polimorfismo). A Lista de Adjacências agora indica os vizinhos com uma lista encadeada (não mais com um vetor).

Ainda falta melhorar o código para componentes conexas e o diâmetro. Provavelmente as funções relacionadas aos graus do vertices também mudarão, já que a classe Vertice não é mais usada pelas classes de representação dos grafos (Graph, AdjacencyLista e AdjacencyMatrix). Mas não deve existir muita dificuldade, ja que a classe Graph possui o método "getNeighbours" que retorna (por referência) um vetor com todos os vizinhos de um vértice.

Uma ideia para o calculo do diametro é fazer a BFS retornar um inteiro que é a altura da arvore geradora criada. 
Uma ideia para as componentes conexas é fazer com que a BFS retorna por referência 2 vetores (encapsulados numa classe?), um com os vetores ordenados conforme são descobertos (para que se possa pegar um vertice não descoberto em O(1)), e um com os tamanhos das componentes conexas.

### Como compilar o programa
    g++ -c -std=c++11 lista.cpp matriz.cpp main.cpp metricas.cpp vertice.cpp vertice-lista.cpp aresta.cpp

### Como link-editar
    g++ -o grafo lista.o matriz.o main.o metricas.o vertice.o vertice-lista.o aresta.o

### Executar
    Linux(Mac): $./grafo <arquivo-texto-com-grafo>
    Windows: grafo.exe <arquivo-texto-com-grafo>

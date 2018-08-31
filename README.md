# teoria-grafos
Repositório do trabalho da disciplina Teoria dos Grafos 2018.2

### Como compilar o programa
  g++ -c vertice.cpp
  g++ -c grafo.cpp
  g++ -c metricas-grafo.cpp
  g++ -std=c++11 -c main.cpp

### Como link-editar
  g++ -o grafo metricas-grafo.o grafo.o vertice.o

### Executar
  Linux(Mac): $./grafo <arquivo-texto-com-grafo>
  Windows: grafo.exe <arquivo-texto-com-grafo>

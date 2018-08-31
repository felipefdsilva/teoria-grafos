# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Teoria dos Grafos - Turma 2018/2
# Prof.Daniel Ratton
# Autores: Felipe Ferreira e Luis Fernando

CCPP=g++
LCPP=g++

CPPFLAGS=-Wall -std=c++11
LPPFLAGS=-Wall -std=c++11

GRAPHOBJS = main.o metricas-grafo.o grafo.o vertice.o

EXECS=grafos

.cpp.o:
	$(CCPP) -c $< $(CCPPFLAGS)

all:$(EXECS)

grafos: $(GRAPHOBJS)
	$(LCPP) -o $@ $? $(LCPPFLAGS)

clean:
	rm -f *.o $(EXECS)

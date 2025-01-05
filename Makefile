DEPENDENCIES_vertex_h = 
DEPENDENCIES_graph_h = $(DEPENDENCIES-vertex_h) vertex.h
DEPENDENCIES_graph_algs_h = $(DEPENDENCIES-graph_h) graph.h

all: graph_algs.o graph.o
	g++ graph_algs.o graph.o -o graph_library

graph_algs.o: graph_algs.cpp $(DEPENDENCIES_graph_algs_h)
	g++ -c graph_algs.cpp

graph.o: graph.cpp $(DEPENDENCIES_graph_h)
	g++ -c graph.cpp


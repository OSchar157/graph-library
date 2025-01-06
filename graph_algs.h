#include "graph/graph.h"

template <typename T>
Graph<T> DFS(Graph<T> graph, Vertex<T> *start);

template <typename T>
std::vector<std::pair<Vertex<T> *, float> > BFS(Graph<T> graph, Vertex<T> *start);

template <typename T>
std::vector<std::pair<Vertex<T> *, float> > dijkstras(Graph<T> graph, Vertex<T> *start);

template <typename T>
std::vector<std::pair<Vertex<T> *, float> > bellman_ford(Graph<T> graph, Vertex<T> *start);

template <typename T>
std::vector<std::pair<Vertex<T> *, float> > shortest_path(Graph<T> graph, Vertex<T> *start);


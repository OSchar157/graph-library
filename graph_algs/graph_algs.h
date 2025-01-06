#ifndef GRAPH_ALGS_H
#define GRAPH_ALGS_H

#include <stdexcept>

#include "../graph/graph.h"

template <typename T>
class GraphAlgorithms
{
public:
    static Graph<T> DFS(Graph<T>& G, Vertex<T>* start_vert)
    {
        if(!G.includes(start_vert))
        {
            throw std::invalid_argument("start_vert not in G");
        }

        Graph<T> result_graph;
        DFS_Helper(G, start_vert, result_graph);
        return result_graph;
    }

    static void DFS_Helper(Graph<T>& G, Vertex<T>* curr, Graph<T>& result_graph)
    {
        result_graph.addVertex(curr);

        for(Neighbor<T>* neighbor : curr->getNeighbors())
        {
            // this shouldn't happen but if it does there's a big logic flaw somewhere
            if(!G.includes(neighbor->getHead()))
            {
                throw std::logic_error("One of the neighbors is not in G");
            }

            if(!result_graph.includes(neighbor->getHead()))
            {
                result_graph.addVertex(neighbor->getHead());
                DFS_Helper(G, neighbor->getHead(), result_graph);
            }
        }
    }
};

/*
TO BE IMPLEMENTED

template <typename T>
std::vector<std::pair<Vertex<T> *, float> > BFS(Graph<T> graph, Vertex<T> *start);

template <typename T>
std::vector<std::pair<Vertex<T> *, float> > dijkstras(Graph<T> graph, Vertex<T> *start);

template <typename T>
std::vector<std::pair<Vertex<T> *, float> > bellman_ford(Graph<T> graph, Vertex<T> *start);

template <typename T>
std::vector<std::pair<Vertex<T> *, float> > shortest_path(Graph<T> graph, Vertex<T> *start);
*/

#endif
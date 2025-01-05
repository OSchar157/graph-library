#include "graph.h"

template <typename T>
void Graph<T>::addVertex(Vertex<T> *new_vert)
{
    graph_map[new_vert];
    vertex_count++;
}

template <typename T>
void Graph<T>::addVertex(Vertex<T> *new_vert,  std::vector<Neighbor<T> *> neighbors)
{
    //iterating through each edge
    for(Neighbor<T> *neighbor : neighbors)
    {
        // check if the edge weight is negative and update the graph
        if(!has_neg_weights && neighbor->getWeight() < 0)
        {
            has_neg_weights = true;
        }

        // if the neighbor vertex of the edge isnt in the graph, add it
        if(!graph_map.count(neighbor->getHead()))
        {
            addVertex(neighbor->getHead());
        }
    }
    
    // update the graph to hold the new vertex with its edges
    graph_map[new_vert] = neighbors;
}

template <typename T>
void Graph<T>::addEdge(Edge<T> *edge)
{
    addEdge(edge->getTail(), edge->getHead(), edge->getWeight());
}

template <typename T>
void Graph<T>::addEdge(Vertex<T> *tail_vert, Neighbor<T> *neighbor)
{
    addEdge(tail_vert, neighbor->getHead(), neighbor->getWeight());
}

template <typename T>
void Graph<T>::addEdge(Vertex<T> *tail_vert, Vertex<T> *head_vert, float weight)
{
    if(!graph_map.count(tail_vert))
    {
        addVertex(tail_vert);
    }

    if(!graph_map.count(head_vert))
    {
        addVertex(head_vert);
    }

    // check if the edge weight is negative and update the graph
    if(!has_neg_weights && weight < 0) 
    {
        has_neg_weights = true;
    }

    // add the edge to the vector of edges of tail vertex
    graph_map[tail_vert].push_back(edge);
    edge_count++;
}

template <typename T>
void Graph<T>::removeEdge(Vertex<T> *tail_vert, Vertex<T> *head_vert)
{
    
}
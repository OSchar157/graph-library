#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "edge.h"
#include "neighbor.h"

#include <utility>
#include <unordered_map>



template <typename T>
class Graph
{
public:
    size_t getEdgeCount() { return edge_count; }
    size_t getVertexCount() { return vertex_count; }
    
    std::vector<Vertex<T> > getVertices();
    std::vector<Edge<T>> getEdges();

    void addVertex(Vertex<T> *new_vert,  std::vector<Neighbor<T> *> neighbors);
    void addVertex(Vertex<T> *new_vert);

    void addEdge(Edge<T> *edge);
    void addEdge(Vertex<T> *tail_vert, Neighbor<T> *neighbor);
    void addEdge(Vertex<T> *tail_vert, Vertex<T> *head_vert, float weight);

    void removeVertex(Vertex<T> *vert_to_rm);

    void removeEdge(Edge<T> *edge_to_rm); // by pointer
    void removeEdge(Edge<T>& edge_to_rm); // by value

    void removeAllEdges(Vertex<T> *tail_vert, Vertex<T> *head_vert);

private:
    /**
     * @brief Map of vertex keys with a vector of vertex-weight pair values representing directed, weighted edges
     */
    std::unordered_map<Vertex<T> *, std::vector<Neighbor<T> *> > graph_map;
    bool has_neg_weights;
    size_t edge_count;
    size_t vertex_count;
};

#endif
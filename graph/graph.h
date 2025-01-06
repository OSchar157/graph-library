#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>

#include "vertex.h"
#include "neighbor.h"
#include "../graph_algs/graph_algs.h"

template <typename T>
class Graph
{
public:
    Graph() : graph_set(std::unordered_set<Vertex<T> *>()), has_neg_weights(false), edge_count(0), vertex_count(0) {}

    size_t getEdgeCount() { return edge_count; }
    size_t getVertexCount() { return vertex_count; }
    bool hasNegWeights() { return has_neg_weights; }

    std::unordered_set<Vertex<T> *> getVertices() { return graph_set; }

    Vertex<T>* addVertex(T value)
    {
        Vertex<T>* new_vert = new Vertex<T>(value);
        graph_set.insert(new_vert);
        vertex_count++;
        return new_vert;
    }

    void addEdge(Vertex<T>* from_vert, Vertex<T>* to_vert, float weight)
    {
        // check if the edge weight is negative and update the graph
        if(!has_neg_weights && weight < 0) 
        {
            has_neg_weights = true;
        }

        // add the edge to the set of neighbors
        Neighbor<T>* new_neighbor = new Neighbor<T>(to_vert, weight);
        from_vert->addNeighbor(new_neighbor);
        edge_count++;
    }

    bool includes(Vertex<T>* vert)
    {
        return graph_set.count(vert) == 1 ? true : false;
    }

    /*
    TO BE IMPLEMENTED

    std::unordered_set<Vertex<T>* > getVertices();
    void removeVertex(Vertex<T>* vert_to_rm);
    void removeAllEdges(Vertex<T>* tail_vert, Vertex<T>* head_vert);
    */

   friend class GraphAlgorithms<T>;

private:
    std::unordered_set<Vertex<T> *> graph_set; //self describing edges
    bool has_neg_weights;
    size_t edge_count;
    size_t vertex_count;

    // for use with the algorithms class
    void addVertex(Vertex<T>* new_vert)
    {
        if(includes(new_vert)) return;
        
        graph_set.insert(new_vert);
    }
};

#endif
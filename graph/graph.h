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
    Graph() : graph_vector(std::vector<Vertex<T> *>()), has_neg_weights(false), edge_count(0), vertex_count(0) {}

    size_t getEdgeCount() { return edge_count; }
    size_t getVertexCount() { return vertex_count; }
    bool hasNegWeights() { return has_neg_weights; }

    std::vector<Vertex<T> *> getVertices() { return graph_vector; }

    Vertex<T>* addVertex(T value)
    {
        Vertex<T>* new_vert = new Vertex<T>(value);
        graph_vector.push_back(new_vert);
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

        // add the edge to the vector of neighbors
        Neighbor<T>* new_neighbor = new Neighbor<T>(to_vert, weight);
        from_vert->addNeighbor(new_neighbor);
        edge_count++;
    }

    bool includes(Vertex<T>* vert)
    {
        return std::find(graph_vector.begin(), graph_vector.end(), vert) != graph_vector.end();
    }

    /*
    TO BE IMPLEMENTED

    std::vector<Vertex<T>* > getVertices();
    void removeVertex(Vertex<T>* vert_to_rm);
    void removeEdge(Vertex<T>* tail_vert, Vertex<T>* head_vert, float weight);
    void removeAllEdges(Vertex<T>* tail_vert, Vertex<T>* head_vert);
    */

   friend class GraphAlgorithms<T>;

private:
    std::vector<Vertex<T> *> graph_vector; //self describing edges
    bool has_neg_weights;
    size_t edge_count;
    size_t vertex_count;

    // for use with the algorithms class
    void addVertex(Vertex<T>* new_vert)
    {
        if(includes(new_vert)) return;
        
        graph_vector.push_back(new_vert);
    }
};

#endif
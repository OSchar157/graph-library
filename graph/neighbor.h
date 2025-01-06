#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include "vertex.h"

// Forward declaration
template <typename T>
class Vertex; 

template <typename T>
class Neighbor
{
public:
    Vertex<T>* getHead() { return head; }
    float getEdgeWeight() { return edge_weight; }
    void updateWeight(float new_weight) { edge_weight = new_weight; }
    
    friend class Graph<T>;

private:
    Neighbor(Vertex<T> *head, float edge_weight) : head(head), edge_weight(edge_weight) {}

    Vertex<T> *head;
    float edge_weight;
};

#endif
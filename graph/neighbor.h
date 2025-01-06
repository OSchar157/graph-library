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
    Vertex<T>* getHead() { return head_vert; }
    float getEdgeWeight() { return edge_weight; }
    void updateWeight(float new_weight) { edge_weight = new_weight; }
    
    ~Neighbor() {}
    
    friend class Graph<T>;

private:
    Neighbor(Vertex<T>* head, float weight) : head_vert(head), edge_weight(weight) {}
    Vertex<T>* head_vert;
    float edge_weight;
};

#endif
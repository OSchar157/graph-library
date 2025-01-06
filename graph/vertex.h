#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

// Forward declaration of Graph
template <typename T>
class Graph;

//forward declaration of Neighbor
template <typename T>
class Neighbor;

template <typename T>
class Vertex
{
public:
    T get_value() { return value; }
    void update_value(T new_val) { value = new_val; }
    std::vector<Neighbor<T>* > getNeighbors() { return neighbors; }

    friend class Graph<T>;
    
private:
    Vertex(T value) : value(value), neighbors(std::vector<Neighbor<T>* >()) {}
    void addNeighbor(Neighbor<T>* neighbor) { neighbors.push_back(neighbor); }
    
    T value;
    std::vector<Neighbor<T>* > neighbors;
};

#include "neighbor.h"

#endif
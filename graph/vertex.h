#ifndef VERTEX_H
#define VERTEX_H

#include <unordered_set>

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
    std::unordered_set<Neighbor<T>* > getNeighbors() { return neighbors; }
    void removeNeighbor(Neighbor<T>* neighbor) { neighbors.erase(neighbor); }

    friend class Graph<T>;
    
private:
    Vertex(T value) : value(value), neighbors(std::unordered_set<Neighbor<T>* >()) {}
    void addNeighbor(Neighbor<T>* neighbor) { neighbors.insert(neighbor); }
    
    T value;
    std::unordered_set<Neighbor<T>* > neighbors;
};

#include "neighbor.h"

#endif
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
    ~Vertex() {}
    const T get_value() const { return value; }
    void update_value(T new_val) { value = new_val; }
    const std::unordered_set<Neighbor<T>* > getNeighbors() const { return neighbors; }
    size_t getNumNeighbors() const { return neighbors.size(); }
    friend class Graph<T>;
    
private:
    Vertex(T value) : value(value), neighbors(std::unordered_set<Neighbor<T>* >()) {}
    void addNeighbor(Neighbor<T>* neighbor) { neighbors.insert(neighbor); }
    void removeNeighbor(Neighbor<T>* neighbor) { neighbors.erase(neighbor); }
    
    T value;
    std::unordered_set<Neighbor<T>* > neighbors;
};

#include "neighbor.h"

#endif
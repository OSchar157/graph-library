#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include "vertex.h"

template <typename T>
class Neighbor
{
public:
    Vector<T> *getHead() { return head; }
    float getWeight() { return weight; }
private:
    Vertex<T> *head;
    float weight;
};  

#endif
#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

template <typename T>
class Edge
{
public:
    Vector<T> *getTail() { return tail; }
    Vector<T> *getHead() { return head; }
    float getWeight() { return weight; }
private:
    Vertex<T> *tail;
    Vertex<T> *head;
    float weight;
};

#endif
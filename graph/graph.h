#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <vector>

#include "vertex.h"
#include "neighbor.h"
#include "../graph_algs/graph_algs.h"

template <typename T>
class Graph
{
public:
    Graph() : graph_set(std::unordered_set<Vertex<T> *>()), has_neg_weights(false), edge_count(0), vertex_count(0) {}
    ~Graph() {}

    size_t getEdgeCount() { return edge_count; }
    size_t getVertexCount() { return vertex_count; }
    bool hasNegWeights() { return has_neg_weights; }

    const std::unordered_set<Vertex<T> *>& getVertices() { return graph_set; }

    Vertex<T>* addVertex(T value) noexcept
    {
        Vertex<T>* new_vert = new Vertex<T>(value);
        graph_set.insert(new_vert);
        vertex_count++;
        return new_vert;
    }

    void addEdge(Vertex<T>* from_vert, Vertex<T>* to_vert, float weight)
    {
        // ensure both vertices are actually in the graph
        if(!includes(from_vert) || !includes(to_vert))
        {
            throw std::invalid_argument("To and from vertices must be in the graph!");
        }

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

    bool includes(Vertex<T>* vert) const noexcept
    {
        return graph_set.count(vert) == 1 ? true : false;
    }

    void removeVertex(Vertex<T>* vert_to_rm)
    {
        if(!includes(vert_to_rm))
        {
            throw std::invalid_argument("Vertex must be in the graph!")
        }

        // find vertices that have vert_to_rm as its neighbor and remove it as a neighbor
        for(Vertex<T>* vert : graph_set)
        {
            std::vector<Neighbor<T>* > neighbors_to_remove;

            for(Neighbor<T>* neighbor : vert->neighbors)
            {
                if(neighbor->head_vert == vert_to_rm)
                {
                    remove.push_back(neighbor);
                }
            }

            for(Neighbor<T>* neighbor : neighbors_to_remove)
            {
                vert->removeNeighbor(neighbor);
                edge_count--;
            }
        }

        size_t num_neighbors = vert_to_rm->getNumNeighbors();

        graph_set.erase(vert_to_rm);
        vertex_count--;
        edge_count -= num_neighbors;
    }

    void removeAllEdges(Vertex<T>* from_vert, Vertex<T>* to_vert)
    {
        if(!includes(tail_vert) || !includes(head_vert))
        {
            throw std::invalid_argument("To and from vertices must be in the graph!")
        }

        from_vert->neighbors.clear();
    }
    
    /*
    TO BE IMPLEMENTED

    */

   friend class GraphAlgorithms<T>;

private:
    std::unordered_set<Vertex<T>* > graph_set; // self describing edges
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
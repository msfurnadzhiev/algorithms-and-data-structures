#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <iostream>
#include "LinkedList.cpp"
using namespace std;

template <typename T>
class Graph {
    LinkedList<LinkedList<T>> graph;

public:
    void addPoint(const T&);
    void addRib(const T&, const T&);
    void deletePoint(const T&);
    void deleteRib(const T&, const T&);
    bool isPointInGraph(const T&);
    bool isRibInGraph(const T&, const T&);
    bool empty() const;
    Node<T>* getPointPtr(const T&);
    void print();
};

#endif //GRAPH_GRAPH_H

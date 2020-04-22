#include "Graph.h"

template <typename T>
void Graph<T>::addPoint(const T& a) {
    LinkedList<T> list;
    list.addNodeToTail(a);
    graph.addNodeToTail(list);
}

template <typename T>
Node<T>* Graph<T>::getPointPtr(const T& a) {
    graph.iterHead();
    Node<LinkedList<T>>* listPtr;
    Node<T>* pointPtr;
    do {
        listPtr = graph.iter();
        listPtr->data.iterHead();
        pointPtr = listPtr->data.iter();
    } while(pointPtr->data != a);

    return pointPtr;
}

template <typename T>
void Graph<T>::addRib(const T& a, const T& b) {
    Node<T>* pointPtr = getPointPtr(a);
    Node<T>* newElem = new Node<T>;
    newElem->data = b;
    newElem->next = pointPtr->next;
    pointPtr->next = newElem;
}

template <typename T>
bool Graph<T>::isPointInGraph(const T& a) {
    if(graph.empty()) {
        return false;
    }

    graph.iterHead();
    Node<LinkedList<T>>* listPtr = graph.iter();
    Node<T>* pointPtr;
    do {
        listPtr->data.iterHead();
        pointPtr = listPtr->data.iter();
        listPtr = listPtr->next;
    } while(pointPtr->data != a && listPtr);

    return pointPtr->data == a;
}

template <typename T>
bool Graph<T>::isRibInGraph(const T& a, const T& b) {
    Node<T>* pointPtr = getPointPtr(a);
    pointPtr = pointPtr->next;
    while (pointPtr && pointPtr->data != b) {
        pointPtr = pointPtr->next;
    }
    return pointPtr != nullptr;
}
template <typename T>
bool Graph<T>::empty() const {
    return graph.empty();
}

template <typename T>
void Graph<T>::deletePoint(const T& a) {
    graph.iterHead();
    Node<LinkedList<T>>* listPtr = graph.iter();
    Node<LinkedList<T>>* tempListPtr;
    while(listPtr) {
        listPtr->data.iterHead();
        Node<T>* pointPtr = listPtr->data.iter();
        if(isRibInGraph(pointPtr->data, a)) {
            deleteRib(pointPtr->data, a);
        }
        listPtr = listPtr->next;
    }

    graph.iterHead();
    Node<T>* pointPtr;
    do {
        tempListPtr = graph.iter();
        tempListPtr->data.iterHead();
        pointPtr = tempListPtr->data.iter();
    } while(pointPtr->data != a);
    LinkedList<T> x;
    graph.deleteNode(tempListPtr, x);
}


template <typename T>
void Graph<T>::deleteRib(const T& a, const T& b) {
    graph.iterHead();
    Node<LinkedList<T>> *listPtr;
    Node<T> *pointPtr;
    do {
        listPtr = graph.iter();
        listPtr->data.iterHead();
        pointPtr = listPtr->data.iter();
    } while (pointPtr->data != a);
    pointPtr = pointPtr->next;
    while(pointPtr->data != b) {
        pointPtr = pointPtr->next;
    }
    T x;
    listPtr->data.deleteNode(pointPtr, x);
}

template <typename T>
void Graph<T>::print() {
    graph.iterHead();
    Node<LinkedList<T>>* listPtr = graph.iter();
    while(listPtr) {
        listPtr->data.print();
        listPtr = graph.iter();
    }
    cout << endl;
}


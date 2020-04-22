#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

//a cell from linked list structure
template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class LinkedList {

    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;

    void deleteList();
    void copyList(LinkedList<T> const &);

public:
    LinkedList();
    LinkedList(LinkedList<T> const &);
    LinkedList& operator= (LinkedList<T> const &);
    ~LinkedList();

    void iterHead(Node<T>* temp = nullptr);
    Node<T>* iter();

    void addNodeToTail(T const &);
    void addNodeAfter(Node<T>*, T const &);
    void addNodeBefore(Node<T>*, T const &);

    bool deleteNodeAfter(Node<T>*, T&);
    bool deleteNodeBefore(Node<T>*, T&);
    bool deleteNode(Node<T>*, T&);

    void print();
    int lengthList();
};

#endif //LINKEDLIST_LINKEDLIST_H

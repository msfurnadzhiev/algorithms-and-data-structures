#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
};

template <typename T>
class DoublyLinkedList {

    Node<T>* head;
    Node<T>* tail;
    Node<T>* currentHead;
    Node<T>* currentTail;

    void deleteList();
    void copyList(DoublyLinkedList<T> const &);

public:
    DoublyLinkedList();
    DoublyLinkedList(DoublyLinkedList<T> const &);
    DoublyLinkedList& operator=(DoublyLinkedList<T> const &);
    ~DoublyLinkedList();

    void iterHead(Node<T>* tempNode = nullptr);
    Node<T>* iterNext();

    void iterTail(Node<T>* tempNode = nullptr);
    Node<T>* iterPrev();

    void addNodeToTail(T const &);
    bool deleteNode(Node<T>*, T&);

    void print();
    void printReverse();
    int length();
};

#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H


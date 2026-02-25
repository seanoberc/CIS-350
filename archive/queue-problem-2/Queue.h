#ifndef ASSIGNMENT_3_QUEUE_H
#define ASSIGNMENT_3_QUEUE_H

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int count;

public:
    Queue();
    ~Queue();

    void enqueue(T element);
    T dequeue();
    // use `const` on the following functions to prevent unintended object modification:
    T peek() const;
    bool isEmpty() const;
    int size() const;
};

#include "Queue.cpp"

#endif //ASSIGNMENT_3_QUEUE_H

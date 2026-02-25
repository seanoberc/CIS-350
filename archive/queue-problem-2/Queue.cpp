#include <stdexcept>
// #include "Queue.h"

using namespace std;

template <typename T>
// constructor to create an instance of an empty queue:
Queue<T>::Queue() : front(nullptr), rear(nullptr), count(0) {}

// destructor is called when instance is out of scope:
template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}


/*
 * `enqueue()` adds a new "job" to the rear:
 */
template <typename T>
void Queue<T>::enqueue(T element) {
    // first, create a new node in the heap to hold the data:
    Node* newNode = new Node(element);

    // check if the queue is empty:
    if (isEmpty()) {
        front = rear = newNode;     // then the new node is both the front and rear
    } else {
        rear->next = newNode;       // point the current rear's 'next' pointer to the new nod

        rear = newNode;
    }
    count++;    // increment the count of total elements within the queue
}

/*
 * `dequeue()` removes the element at the front and returns that element's value:
 */
template <typename T>
T Queue<T>::dequeue() {
    // check if the queue is empty:
    if (isEmpty()) {
        throw underflow_error("ERROR: The queue is empty.");    // TODO: print the error in the main method
    }

    // temp pointer to save value of current front:
    Node* temp = front;
    T data = temp->data;

    // move front pointer to next:
    front = front->next;

    // if, after moving the front of the queue, the queue is now empty, set the rear to null too:
    if (front == nullptr) {
        rear = nullptr;
    }

    // free memory from original fron node:
    delete temp;
    count--;    // decrement job count
    return data;    // get the data that was at front
}


/*
 * `peek()` allows inspection of the first job without having to first remove it:
 */
template <typename T>
T Queue<T>::peek() const {
    // check if queue is empty (can't look at an empty queue):
    if (isEmpty()) {
        throw underflow_error("ERROR: The queue is empty.");    // TODO: print the error in the main method
    }

    return front->data;     // return data stored in front node
}


/*
 * `isEmpty()` is a helper function to check whether the queue is holding any jobs:
 */
template <typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;      // returns true if job count is zero
}


/*
 * `size()` function returns the current number of queued jobs:
 */
template <typename T>
int Queue<T>::size() const {
    return count;
}
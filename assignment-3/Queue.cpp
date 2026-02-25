#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node *next;
        Node(T val) : data(val), next(nullptr) {
        }
    };

    Node *front;
    Node *rear;
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

template<typename T>
// constructor to create an instance of an empty queue:
Queue<T>::Queue() : front(nullptr), rear(nullptr), count(0) {
}

// destructor is called when instance is out of scope:
template<typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}


/*
 * `enqueue()` adds a new "job" to the rear:
 */
template<typename T>
void Queue<T>::enqueue(T element) {
    // first, create a new node in the heap to hold the data:
    Node *newNode = new Node(element);

    // check if the queue is empty:
    if (isEmpty()) {
        front = rear = newNode; // then the new node is both the front and rear
    } else {
        rear->next = newNode; // point the current rear's 'next' pointer to the new nod

        rear = newNode;
    }
    count++; // increment the count of total elements within the queue
}

/*
 * `dequeue()` removes the element at the front and returns that element's value:
 */
template<typename T>
T Queue<T>::dequeue() {
    // check if the queue is empty:
    if (isEmpty()) {
        throw underflow_error("ERROR: The queue is empty."); // TODO: print the error in the main method
    }

    // temp pointer to save value of current front:
    Node *temp = front;
    T data = temp->data;

    // move front pointer to next:
    front = front->next;

    // if, after moving the front of the queue, the queue is now empty, set the rear to null too:
    if (front == nullptr) {
        rear = nullptr;
    }

    // free memory from original fron node:
    delete temp;
    count--; // decrement job count
    return data; // get the data that was at front
}


/*
 * `peek()` allows inspection of the first job without having to first remove it:
 */
template<typename T>
T Queue<T>::peek() const {
    // check if queue is empty (can't look at an empty queue):
    if (isEmpty()) {
        throw underflow_error("ERROR: The queue is empty."); // TODO: print the error in the main method
    }

    return front->data; // return data stored in front node
}


/*
 * `isEmpty()` is a helper function to check whether the queue is holding any jobs:
 */
template<typename T>
bool Queue<T>::isEmpty() const {
    return count == 0; // returns true if job count is zero
}


/*
 * `size()` function returns the current number of queued jobs:
 */
template<typename T>
int Queue<T>::size() const {
    return count;
}


/*
 * `main()` method for empulating the print spooler
 */
int main(int argc, char *argv[]) {
    // 1. create an instance of a queue for printing strings
    Queue<string> printSpooler;

    // 2. add jobs to print queue
    cout << "Loading jobs into the queue..." << '\n';
    printSpooler.enqueue("Annual_Report.docx");
    printSpooler.enqueue("Family_Photo.png");
    printSpooler.enqueue("Data_Sheet.xlsx");

    // 3.  print the current size of the queue and show the job at the front using `peek()`
    cout << "Jobs currently queued:" << printSpooler.size() << '\n';
    cout << "Next print job:" << printSpooler.peek() << "\n\n";

    // 4. process two jobs from the print queue
    for (int i = 0; i < 2; i++) {
        if (!printSpooler.isEmpty()) {
            cout << "Processing job: " << printSpooler.dequeue() << '\n';
            cout << "Jobs remaining: " << printSpooler.size() << '\n';
        } else {
            cout << "Process complete." << '\n';
            break;
        }
    }

    // 5. add two new jobs to the queue
    cout << "Adding two new jobs..." << '\n';
    printSpooler.enqueue("Essay_Outline.pdf");
    printSpooler.enqueue("Rental_VINs.csv");

    // 6. print new size of queue and show current job at front
    cout << "Jobs queued:" << printSpooler.size() << '\n';
    cout << "Current job:" << printSpooler.peek() << "\n\n";

    // 7. process remaining jobs in queue
    while (!printSpooler.isEmpty()) {
        cout << "Processing remaining jobs: " << printSpooler.dequeue() << '\n';
    }

    // 8. verify the queue is empty
    cout << "Is the queue empty? ";
    if (printSpooler.isEmpty()) {
        cout << "Yes (True)" << '\n';
    } else {
        cout << "No (False)" << '\n';
    }
    cout << '\n';

    // 9. demonstrate underflow error handling
    try {
        cout << "Attempting to dequeue from an empty queue..." << '\n';
        printSpooler.dequeue();
    } catch (const underflow_error &e) {
        cerr << "Exception caught: " << e.what() << '\n';
    }
}

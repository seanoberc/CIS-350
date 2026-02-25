#include <iostream>
#include "DLinkedList.h"

using namespace std;

int main() {

    // Initialize a DLinkedList object
    DLinkedList list;

    cout << "--- 1. Testing on an empty list ---" << endl;
    cout << "Is the list empty? " << (list.empty() ? "True" : "False") << endl;
    cout << "List contents: ";
    list.printList(); // Should print "List is empty"
    cout << "Attempting to remove from an empty list..." << endl;
    // list.removeFront(); // Should handle gracefully
    // list.removeBack();  // Should handle gracefully
    if (!list.empty()) list.removeFront();
    if (!list.empty()) list.removeBack();

    cout << endl;

    cout << "--- 2. Populating the list ---" << endl;
    cout << "Adding elements: SFO, PVD (front) and JFK, BOS (back)" << endl;
    list.addFront("PVD");
    list.addFront("SFO");
    list.addBack("JFK");
    list.addBack("BOS");

    cout << "Current list: ";
    list.printList();
    cout << "Front element: " << list.front() << endl;
    cout << "Back element: " << list.back() << endl;
    cout << "Is the list empty? " << (list.empty() ? "True" : "False") << endl;
    cout << endl;

    cout << "--- 3. Testing find() function ---" << endl;
    list.find("PVD"); // Element in the middle
    list.find("SFO"); // First element
    list.find("BOS"); // Last element
    list.find("MIA"); // Non-existent element
    cout << endl;

    cout << "--- 4. Testing insertAfter() function ---" << endl;
    cout << "Inserting 'BWI' after 'PVD'..." << endl;
    list.insertAfter("PVD", "BWI");
    cout << "List after insertion: ";
    list.printList();

    cout << "Attempting to insert 'MIA' after non-existent 'LAX'..." << endl;
    list.insertAfter("LAX", "MIA");
    cout << "List remains: ";
    list.printList();
    cout << endl << endl;

    cout << "--- 5. Testing reverse() function ---" << endl;
    cout << "Reversing the list..." << endl;
    list.reverse();
    cout << "List after reverse: ";
    list.printList();
    cout << "New front element: " << list.front() << endl;
    cout << "New back element: " << list.back() << endl;
    cout << endl;

    cout << "--- 6. Testing removeFront() and removeBack() ---" << endl;
    cout << "Removing from front..." << endl;
    list.removeFront();
    cout << "List after removeFront: ";
    list.printList();

    cout << "Removing from back..." << endl;
    list.removeBack();
    cout << "List after removeBack: ";
    list.printList();
    cout << endl << endl;

    cout << "--- 7. Emptying the list ---" << endl;
    list.removeBack();
    list.removeBack();
    list.removeBack();
    cout << "List after removing all elements: ";
    list.printList();
    cout << "Is the list empty? " << (list.empty() ? "True" : "False") << endl;

    return 0;
}
#include <iostream>
#include "DLinkedList.h"

using namespace std;

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->right = trailer;
    trailer->left = header;
}

DLinkedList::~DLinkedList() {
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const {
    return (header->right == trailer) && (trailer->left == header);
}

const Ele& DLinkedList::front() const {
    return header->right->ele;
}

const Ele& DLinkedList::back() const {
    return trailer->left->ele;
}

DNode* DLinkedList::findNode(const Ele& e) {
    DNode* temp = header->right;
    while (temp != trailer && temp->ele != e) {
        temp = temp->right;
    }
    return (temp != trailer) ? temp : nullptr; // Return nullptr if not found
}

void DLinkedList::addFront(const Ele& e) {
    addBefore(header->right, e);
}

void DLinkedList::removeFront() {
    remove(header->right);
}

void DLinkedList::printList() const {
    DNode* temp = header->right;

    if (temp == trailer) {  // List is empty if header's right points to trailer
        cout << "List is empty" << endl;
        return;
    }

    while (temp != trailer) {
        cout << temp->ele;
        if (temp->right != trailer) {
            cout << " -> ";
        }
        temp = temp->right;
    }
}

void DLinkedList::addBefore(DNode* v, const Ele& e) { // add before v
    DNode* u = new DNode;
    u->ele = e;
    u->right = v;
    u->left = v->left;
    v->left->right = u;
    v->left = u;
}

void DLinkedList::remove(DNode* v) {
    DNode* u = v->left;
    DNode* w = v->right;
    u->right = w;
    w->left = u;
    delete v;
}

/*
* Find the first occurrence of the specified element (element) in
* the list. Return an integer indicating the position of the element found
* in the
* list containing the element if found, otherwise return -1. If the element
* is found, print a message indicating its position in the list.
 */
int DLinkedList::find(const Ele& element) {
    int pos = 1;    // begin counting at position 1
    const DNode *currNode = header->right;  // start at first real node

    while (currNode != trailer) {   // traverse list until sentinel is reached
        if (currNode->ele == element) {
            cout << "Element '" << element << "' found at position " << pos << "\n";
            return pos;
        }
        currNode = currNode->right; // move to the next node
        ++pos;  // increment the counter
    }
    cout << "Element '" << element << "' not found in the list.\n";
    return -1;  // not found
}

/*
*  Insert a new element (newElement) after a given element
*  (existingElement). If the existingElement is not found, print a
*  suitable message.
 */
void DLinkedList::insertAfter(const Ele& existingElement, const Ele&
newElement) {
    DNode *currNode = header->right;

    while (currNode != trailer) {
        if (currNode->ele == existingElement) {
            auto *newNode = new DNode;  // Clang-Tidy: Use auto when initializing with new to avoid duplicating the type name
            newNode->ele = newElement;

            // shift the pointers:
            newNode->left = currNode;
            newNode->right = currNode->right;
            currNode->right->left = newNode;
            currNode->right = newNode;
            return; // return after one insertion
        }
        currNode = currNode->right;
    }
    // if `existingElement` is not in the list:
    cout << "Element could not be found.";
}

/*
* Reverse the order of elements in the list. This operation should
* modify the list in place so that the last element now becomes the first
* element, second last becomes the second element and so on in the modified
* list. When printed by the printList() function it print the list in
* reverse order.
 */
void DLinkedList::reverse() {
    DNode *currNode = header;   // begin traversing from header sentinel

    // swap left and right pointers for each node in list:
    while (currNode != nullptr) {
        DNode *temp = currNode->left;
        currNode->left = currNode->right;
        currNode->right = temp;
        // move "forward" in the original direction:
        currNode = currNode->left;
    }
    // swap header and trailer sentinels:
    DNode *temp = header;
    header = trailer;
    trailer = temp;
}

/*
 * Add a new element (newElement) at the back of the list.
 */
void DLinkedList::addBack(const Ele& e) {
    auto *newNode = new DNode;  // Clang-Tidy: Use auto when initializing with new to avoid duplicating the type name
    newNode->ele = e;

    // insert a new node
    newNode->right = trailer;
    newNode->left = trailer->left;
    trailer->left->right = newNode;
    trailer->left = newNode;
}

/*
 * Remove an element from the back of the list.
 */
void DLinkedList::removeBack() {
    if (empty()) {
        return;
    }

    remove(trailer->left);
}

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

void DLinkedList::addBefore(DNode* v, const Ele& e) { // add before v
    DNode* u = new DNode;
    u->ele = e;
    u->right = v;
    u->left = v->left;
    v->left->right = u;
    v->left = u;
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

void DLinkedList::remove(DNode* v) {
    DNode* u = v->left;
    DNode* w = v->right;
    u->right = w;
    w->left = u;
    delete v;
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
        cout << temp->ele << endl;
        temp = temp->right;
    }
}


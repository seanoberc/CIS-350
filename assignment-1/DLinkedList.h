#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H 1

using namespace std;

typedef string Ele;

class DNode {
private:
    Ele ele;
    DNode* left;
    DNode* right;
    friend class DLinkedList;
};

class DLinkedList {
private:
    DNode* header;
    DNode* trailer;
protected:

public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Ele& front() const;
    const Ele& back() const;
    DNode* findNode(const Ele& e);
    void addFront(const Ele& e);
    void removeFront();
    void printList() const;
    void addBefore(DNode* v, const Ele& e); // add before v
    void remove(DNode* v);
    int find(const Ele& e); //1.todo 
    void insertAfter(DNode* v, const Ele& e); //2. todo add after v
    void reverse(DLinkedList& L); // 3. todo reverse the list in place
    void addBack(const Ele& e); // 4. todo
    void removeBack();  // 5. todo
    friend class DLinkedListTest;
};

#endif
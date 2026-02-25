#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;

    // constructor and initializer list  for node:
    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

/*
 * `preorderNext()` returns the node visited after node v in preorder
 * traversal of T
 */
Node* preorderNext(Node* v) {
    if (v == nullptr) {
        return nullptr;
    }

    // the next is the left child if it exits
    if (v->left != nullptr) {
        return v->left;
    }
    // the right is next if it exists and the left does not exist
    if (v->right != nullptr) {
        return v->right;
    }

    // climb up the tree to find the next, unvisited right sibling
    Node* current = v;
    while (current->parent != nullptr) {
        Node* parent = current->parent;
        // if climbing up from the left child and the parent has a right child:
        if (parent->left == current && parent->right != nullptr) {
            return parent->right;
        }
        current = parent;
    }
    // return null if the root is reached without finding a next node
    return nullptr;
}


/*
 * `inorderNext()` returns the node visited after node v in b UBorder
 * traversal of T
 */
Node* inorderNext(Node* v) {
    if (v == nullptr) return nullptr;

    // if a right child exists, the next node is left-most node in right subtree:
    if (v->right != nullptr) {
        Node* current = v->right;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // if a right child does not exist, keep climbing until the current is not a right child:
    Node* current = v;
    while (current->parent != nullptr && current->parent->right == current) {
        current = current->parent;
    }
    // set the current as the parent:
    return current->parent;
}


/*
 * `postorderNext()` returns the node visited after node v in postorder
 * traversal of T
 */
Node* postorderNext(Node* v) {
    if (v == nullptr) return nullptr;

    // if `v` is the root node, then there is no parent:
    if (v->parent == nullptr) {
        return nullptr;
    }

    Node* parent = v->parent;

    // if `v` is the right child (or it is the left child and there’s no right child), then return the parent as the next node:
    if (parent->right == nullptr || parent->right == v) {
        return parent;
    }

    // if `v` is the left child and the parent has a right child:
    Node* current = parent->right;
    // look for the first node in the postorder traversal of right sub-tree:
    while (current->left != nullptr || current->right != nullptr) {
        if (current->left != nullptr) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return current;
}


/*
 * main method to test traversal functions:
 */
int main() {
    Node* root = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);

    // link nodes:
    root->left = n2;
    n2->parent = root;
    root->right = n3;
    n3->parent = root;

    n2->left = n4;
    n4->parent = n2;
    n2->right = n5;
    n5->parent = n2;

    n3->left = n6;
    n6->parent = n3;
    n3->right = n7;
    n7->parent = n3;

    // preorder test:
    Node* currentPre = root;
    while (currentPre != nullptr) {
        cout << currentPre->data << " ";
        currentPre = preorderNext(currentPre);
    }
    cout << '\n';

    // inorder test
    Node* currentIn = n4;
    while (currentIn != nullptr) {
        cout << currentIn->data << " ";
        currentIn = inorderNext(currentIn);
    }
    cout << '\n';

    // postorder test
    Node* currentPost = n4;
    while (currentPost != nullptr) {
        cout << currentPost->data << " ";
        currentPost = postorderNext(currentPost);
    }
    cout << '\n';

    // de-allocate memory:
    delete root;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;

    return 0;
}

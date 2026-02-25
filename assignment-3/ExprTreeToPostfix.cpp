#include <iostream>
#include <string>

using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;

    // node constructor and initializer list:
    Node(string val) : value(val), left(nullptr), right(nullptr) {}
};

// recursively print tree as postfix:
void printPostfix(Node* root) {
    // check whether the tree is empty:
    if (root == nullptr) {
        return;
    }

    // traverse left subtree:
    printPostfix(root->left);

    // traverse right subtree:
    printPostfix(root->right);

    // print current node:
    cout << root->value << " ";
}

int main() {
    // instantiate root node:
    Node* root = new Node("/");

    // assign first level of node:
    root->left = new Node("*");
    root->right = new Node("4");

    // assign second level of node:
    root->left->left = new Node("+");
    root->left->right = new Node("-");

    // assign third level of node:
    root->left->left->left = new Node("5");
    root->left->left->right = new Node("2");
    root->left->right->left = new Node("8");
    root->left->right->right = new Node("3");

    // output postfix:
    cout << "infix: ((5+2)*(8-3))/4" << endl;
    cout << "postfix: ";
    printPostfix(root);
    cout << '\n';

    // de-allocate memory:
    // first level
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->right->left;
    delete root->left->right->right;
    // second level
    delete root->left->left;
    delete root->left->right;
    delete root->right;
    // third level
    delete root->left;
    delete root;

    return 0;
}
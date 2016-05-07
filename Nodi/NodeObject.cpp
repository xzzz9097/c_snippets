#include "NodeObject.h"

using namespace std;

void NodeObject::addOnTop(int content) {
    struct Node *updatedNode = new Node;

    updatedNode -> content = content;
    updatedNode -> next = node;

    node = updatedNode;
}

void NodeObject::removeFromTop() {
    struct Node *deletedNode = new Node;

    deletedNode = node;

    node = node -> next;

    delete deletedNode;
}

void NodeObject::print() {
    struct Node *helperNode = new Node;

    helperNode = node;
    while (helperNode != NULL) {
        cout << "Element: " << helperNode -> content << endl;
        helperNode = helperNode -> next;
    }
}

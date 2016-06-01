#include "NodeObject.h"

using namespace std;

NodeObject::NodeObject() {
    node = NULL;
}

NodeObject::NodeObject(int content, struct Node *next) {
    node = new Node;

    node -> content = content;
    node -> next = next;
}

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

struct NodeObject::Node * NodeObject::getNode() {
    return node;
}

struct NodeObject::Node * NodeObject::searchNode(int content) {
    struct Node *helperNode = new Node;

    helperNode = node;
    while (helperNode != NULL) {
        if (helperNode -> content == content) {
            return helperNode;
        } else {
            helperNode = helperNode -> next;
        }
    }

    return NULL;
}

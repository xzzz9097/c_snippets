/* Header file for node class */
#include <iostream>
#include <stddef.h>

class NodeObject {
  public:
    struct Node {
        int content;
        Node *next;
    };

  private:
    struct Node *node;
public:
    NodeObject();
    NodeObject(int, struct Node *);

    void addOnTop(int);
    void removeFromTop();
    void print();

    struct Node * getNode();
    struct Node * searchNode(int);
};

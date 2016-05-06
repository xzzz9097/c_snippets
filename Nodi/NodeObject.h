/* Header file for node class */
#include <iostream>
#include <stddef.h>

class NodeObject {
    struct Node {
        int content;
        Node *next;
    };

    struct Node *node = NULL;
public:
    void addOnTop(int);
    void removeFromTop();
    void print();
};

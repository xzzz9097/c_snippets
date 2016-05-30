#include "NodeObject.h"

using namespace std;

int main() {
    NodeObject mNode;

    mNode.addOnTop(5);
    mNode.addOnTop(4);
    
    mNode.removeFromTop();

    mNode.print();
}

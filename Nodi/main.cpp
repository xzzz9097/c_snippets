#include "NodeObject.h"

using namespace std;

int main() {
    NodeObject mList;

    mList.addOnTop(5);
    mList.addOnTop(4);
    mList.addOnTop(7);

    struct NodeObject::Node * mNode = mList.searchNode(6);

    if (mNode != NULL) {
        cout << mNode -> content << endl;
    }

    mList.print();
}

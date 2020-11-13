#include "Tree.h"

RootTree * RootTree::clone() const {
    return new RootTree(this->getNode());
}
//constructor
RootTree::RootTree(int rootLabel) : Tree(rootLabel){}

//copy constructor
RootTree::RootTree(const RootTree &likeThis):Tree(likeThis) {}

int RootTree::traceTree() {
    return getNode();
}

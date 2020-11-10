#include "Tree.h"

RootTree * RootTree::clone() {
    return new RootTree(this->getNode());
}
//constructor
RootTree::RootTree(int rootLabel) : Tree(rootLabel){}

//copy constructor


//copy assignment operator

//move constructor

//move assignment operator
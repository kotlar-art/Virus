#include "Tree.h"

//constructor
MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {}

//copy constructor

//copy assignment operator

//move constructor

//move assignment operator

MaxRankTree * MaxRankTree::clone() {
    MaxRankTree *ct = new MaxRankTree(getNode());
    if (getChildren().size()==0) return ct;
    for (unsigned int i = 0; i<getChildren().size(); i++){
        ct->addChild(this->getChildren()[i]->clone());
    }
    return ct;
}
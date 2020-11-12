#include "Tree.h"

//constructor
MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {}

//copy constructor
MaxRankTree::MaxRankTree(const MaxRankTree &likeThis): Tree(likeThis) {
    if (likeThis.getChildren().size()!=0){
        for (unsigned int i = 0; i<likeThis.getChildren().size(); i++){
            Tree *MRT = likeThis.getChildren()[i]->clone();
            addChild(MRT);
        }
    }
}

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
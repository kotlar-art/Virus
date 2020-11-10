//
// Created by spl211 on 10/11/2020.
//

#include "Tree.h"
//constructor
CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel), currCycle(currCycle){};

CycleTree * CycleTree::clone() {
    CycleTree *ct = new CycleTree(getNode(),currCycle);
    if (getChildren().size()==0) return ct;
    for (unsigned int i = 0; i<getChildren().size(); i++){
        ct->addChild(this->getChildren()[i]->clone());
    }
    return ct;
}


//copy constructor
CycleTree::CycleTree(const CycleTree &likeThis): Tree(likeThis) {
    if(likeThis.getChildren().size()!=0){
        for (unsigned int i = 0; i<likeThis.getChildren().size();i++){
            Tree *ct = likeThis.getChildren()[i]->clone();
            addChild(ct);
        }
    }
}

//copy assignment operator

//move constructor

//move assignment operator
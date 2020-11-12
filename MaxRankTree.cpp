#include "Tree.h"

//constructor
MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {}

//copy constructor
MaxRankTree::MaxRankTree(const MaxRankTree &likeThis): Tree(likeThis) {
    if(likeThis.getChildren().size()!=0){
        for (unsigned int i = 0; i<likeThis.getChildren().size();i++){
            Tree *ct = likeThis.getChildren()[i]->clone();
            addChild(ct);
        }
    }
}


MaxRankTree * MaxRankTree::clone() const{
    MaxRankTree *ct = new MaxRankTree(getNode());
    if (getChildren().size()==0) return ct;
    for (unsigned int i = 0; i<getChildren().size(); i++){
        ct->addChild(this->getChildren()[i]->clone());
    }
    return ct;
}
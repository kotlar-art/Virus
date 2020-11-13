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

int MaxRankTree::traceTree() {
   std::pair<int,int> pair = trace();
    return pair.first;
}

std::pair<int, int> MaxRankTree::trace() {
    std::pair<int,int> output(getNode(), getChildren().size());
    for (int i = 0; i < getChildren().size(); ++i) {
        std::pair<int,int> toCompare =((MaxRankTree *)(getChildren()[i]))->trace();
        if(toCompare.second > output.second){
            output.first = toCompare.first;
            output.second = toCompare.second;
        }
    }
    return output;
}

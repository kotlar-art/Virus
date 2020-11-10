
#include <iostream>
#include "Session.h"
#include "Tree.h"
#include "Graph.h"
#include <vector>
using namespace std;

//constructor
Tree::Tree(int rootLabel) : node(rootLabel), children(0){};
//copy constructor
Tree::Tree(const Tree &likeThis): node(likeThis.node), children(0){
    for(auto& elem: likeThis.children){
        addChild(elem->clone());
    }
}
//copy assignment operator

//move constructor

//move assignment operator

Tree * Tree::createTree(const Session &session, int rootLabel) {
    TreeType t = session.getTreeType();
    if (t==Root){
        RootTree *RT = new RootTree(rootLabel);
        return RT;
    }
    vector<vector<int>> vic = session.getGraph().getEdges();
    if(t==Cycle){

    }
    else{

    }
}
void Tree::addChild(Tree *child) {
    this->children.push_back(child);
}
vector<Tree *> Tree::getChildren() const{
    return children;
}
void Tree::addChild(const Tree &child) {

}


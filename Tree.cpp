
#include <iostream>
#include "Session.h"
#include "Tree.h"
#include "Graph.h"
#include <vector>
#include <queue>
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

Tree * Tree::BFS(const Session &session, int rootLabel) {
    vector<bool> visited(session.getGraph().getGraphSize());
    queue<Tree*> *q = new queue<Tree*>;
    visited[rootLabel] = true;
    Tree *t = createTree(session, rootLabel);
    q->push(t);
    q->front()->BFS(session, *q, visited);
    delete q;
    return t;
}

void Tree::BFS(const Session &session, queue<Tree*>& q, vector<bool>& visited) {

        int node = q.front()->getNode();
        for (unsigned int i = 0; i<session.getGraph().getEdges()[node].size(); i++){
            if (session.getGraph().getEdges()[node][i]==1&&visited[i]==false){
                visited[i]=true;
                Tree *child = createTree(session, i);
                addChild(child);
                q.push(child);
            }
        }
        q.pop();
        q.front()->BFS(session,q,visited);
}

Tree * Tree::createTree(const Session &session, int rootLabel) {
    TreeType t = session.getTreeType();
    if (t==Root){
        RootTree *RT = new RootTree(rootLabel);
        return RT;
    }
//    vector<vector<int>> vic = session.getGraph().getEdges();
    if(t==Cycle){
        CycleTree *CT = new CycleTree(rootLabel, session.getCycle());
        return CT;
    }
    else{
        MaxRankTree *MRT = new MaxRankTree(rootLabel);
        return MRT;
    }
}
void Tree::addChild(Tree *child) {
    if (child != nullptr){
        this->children.push_back(child);
    }
}
vector<Tree *> Tree::getChildren() const{
    return children;
}
void Tree::addChild(const Tree &child) {

}


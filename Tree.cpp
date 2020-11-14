
#include "Session.h"
#include "Tree.h"
#include "Graph.h"
#include <vector>
#include "iostream"

using namespace std;

//constructor
Tree::Tree(int rootLabel) : node(rootLabel), children(0){};

//destructor
Tree::~Tree() {clear();}
//copy constructor
Tree::Tree(const Tree &likeThis): node(likeThis.node), children(0){
    for(auto& elem: likeThis.children){
        addChild(elem->clone());
    }
}
//copy assignment operator
const Tree& Tree::operator=(const Tree &other) {
    if(this != &other) {
        clear();
        node = other.getNode();
        for (auto &i :other.getChildren()) {
            addChild(i->clone());
        }
    }
    return *this;
}

//move constructor
Tree::Tree(Tree &&other) {
    node = other.getNode();
    children = other.children;
    other.children.clear();
}

//move assignment operator
const Tree& Tree::operator=(Tree &&other) {
    clear();
    node = other.getNode();
    children = other.children;
    other.children.clear();
    return *this;
}

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

    int TreeRoot = q.front()->getNode();
    for (unsigned int i = 0; i < session.getGraph().getEdges()[TreeRoot].size(); i++) {
        if (session.getGraph().getEdges()[TreeRoot][(int)i] == 1 && !visited[(int)i]) {
            visited[(int)i] = true;
            Tree *child = createTree(session, (int)i);
            addChild(child);
            q.push(child);
        }
    }
    q.pop();
    if(!q.empty()) q.front()->BFS(session, q, visited);

}
//debugging
void Tree::print() {
    cout << getNode();
    cout << "{";
    for (int i = 0; i < getChildren().size(); ++i) {
        (getChildren()[i])->print();
        cout << ", ";
    }
    cout << '}';
}


void Tree::clear() {
    for (auto & i : children) {
        delete i;
    }
    children.clear();
}

Tree * Tree::createTree(const Session &session, int rootLabel) {
    TreeType t = session.getTreeType();
    if (t==Root){
        RootTree *RT = new RootTree(rootLabel);
        return RT;
    }
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
    if(child != nullptr){
        children.push_back(child);
    }
}

void Tree::addChild(const Tree &child) {
    Tree* clone = child.clone();
    children.push_back(clone);
}

int Tree::getNode() const {
    return node;
}

vector<Tree *> Tree::getChildren() const{
    return children;
}





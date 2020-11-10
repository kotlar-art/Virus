

#ifndef TREE_H_
#define TREE_H_
#include "Graph.h"
#include <vector>
using namespace std;

class Session;

class Tree{
public:
    //rule of 5
    Tree(int rootLabel);
    Tree(const Tree& likeThis);//copy constructor
    //rule of 5//
    void addChild(const Tree& child);
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    virtual Tree* clone()=0;
    vector<Tree*> getChildren() const;
    void addChild(Tree* child);
    int getNode() const;
private:
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
public:
    //rule of 5
    CycleTree(int rootLabel, int currCycle);
    CycleTree(const CycleTree& likeThis);
    //rule of 5

    virtual int traceTree();
    virtual CycleTree* clone();
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    //rule of 5
    MaxRankTree(int rootLabel);//constructor
    MaxRankTree(const MaxRankTree& likeThis);//copy constructor;
    //rule of 5

    virtual int traceTree();
    virtual MaxRankTree* clone();
};

class RootTree: public Tree{
public:
    //rule of 5
    RootTree(int rootLabel);
    //rule of 5
    virtual RootTree* clone();
    virtual int traceTree();
};

#endif


#ifndef TREE_H_
#define TREE_H_
#include "Graph.h"
#include <vector>
#include <queue>
using namespace std;

class Session;

class Tree{
public:

    Tree(int rootLabel);//constructor
    //rule of 5
    virtual ~Tree();//destructor
    Tree(const Tree& likeThis);//copy constructor
    const Tree& operator=(const Tree& likeThis);//assignment operator
    //rule of 5//
    void addChild(const Tree& child);
    static Tree* BFS(const Session& session, int rootLabel);
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    virtual Tree* clone()=0;
    vector<Tree*> getChildren() const;
    void addChild(Tree* child);
    int getNode() const;
private:
    int node;
    std::vector<Tree*> children;
    void BFS(const Session& session, queue<Tree*>& q, vector<bool>& visited);
};

class CycleTree: public Tree{
public:

    CycleTree(int rootLabel, int currCycle);//constructor
    //rule of 5
    CycleTree(const CycleTree& likeThis);//copy constructor
    virtual ~CycleTree();//destructor
    const CycleTree& operator=(const CycleTree& likeThis);//assignment operator
    //rule of 5

    virtual int traceTree();
    virtual CycleTree* clone();
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:

    MaxRankTree(int rootLabel);//constructor
    //rule of 5
    MaxRankTree(const MaxRankTree& likeThis);//copy constructor;
    virtual ~MaxRankTree();//destructor
    const MaxRankTree& operator=(const MaxRankTree& likeThis);
    //rule of 5

    virtual int traceTree();
    virtual MaxRankTree* clone();
};

class RootTree: public Tree{
public:

    RootTree(int rootLabel);
    //rule of 5
    RootTree(const RootTree& likeThis);//copy constructor
    virtual ~RootTree();//destructor
    const RootTree& operator=(const RootTree& likeThis);//assignment operator
    //rule of 5
    virtual RootTree* clone();
    virtual int traceTree();
};

#endif
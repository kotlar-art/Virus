#ifndef SESSION_H_
#define SESSION_H_
#include "json.hpp"
#include <vector>
#include <string>
#include "Graph.h"
#include "Agent.h"

class Agent;

enum TreeType{
    Cycle,
    MaxRank,
    Root
};

class Session{
public:
    //rule of 5
    Session(const std::string& path);
    Session(const Session& session);
    //rule of 5

    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    const Graph& getGraph() const;
    void enqueueInfected(int a);
    int dequeueInfected();
    int getListSize() const;
    TreeType getTreeType() const;

private:
    vector<int> infectedList;
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
};

#endif
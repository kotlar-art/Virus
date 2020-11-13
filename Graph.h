#ifndef GRAPH_H_
#define GRAPH_H_
#include <vector>
#include "Tree.h"
using namespace std;


class Graph{
public:
    Graph();
    Graph(Graph const &t);
    Graph(std::vector<std::vector<int>> matrix);
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    void remove_edge(int i, int j);
    vector<int> getNeighbors(int node);
    void set_graph(std::vector<std::vector<int>> matrix);
    const vector<vector<int>> getEdges() const;
    vector<bool> getList();
    int getGraphSize() const;
    void amputate(int toAmputate);
private:
    std::vector<std::vector<int>> edges;
    std::vector<bool> infected_list;
};

#endif
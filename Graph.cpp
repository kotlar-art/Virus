
#include "Graph.h"
#include "Tree.h"
#include <iostream>
using namespace std;

Graph::Graph():edges(std::vector<std::vector<int>>()), infected_list(std::vector<bool>(edges.size())) {}
Graph::Graph(std::vector<std::vector<int>> matrix): edges(matrix), infected_list(std::vector<bool>(edges.size())) {}
Graph::Graph(Graph const &t): edges(t.edges), infected_list(t.infected_list){}

void Graph::set_graph(std::vector<std::vector<int>> matrix) {
    edges = matrix;
}
bool Graph::isInfected(int nodeInd) {
    return infected_list[nodeInd];
}

void Graph::infectNode(int nodeInd) {
    infected_list[nodeInd] = true;
}

    const vector<vector<int>> Graph::getEdges() const {
    return edges;
}

int Graph::getGraphSize() const {
    return edges.size();
}

vector<int> Graph::getNeighbors(int node) {
    vector<int> neighbors;
    for (int i = 0; i < edges.size(); ++i) {
        if(edges[node][i] == 1){
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

vector<bool> Graph::getList(){
    return infected_list;
}

void Graph::remove_edge(int i, int j) {
    edges[i][j] = 0;
    edges[j][i] = 0;
}

void Graph::amputate(int toAmputate) {
    for (unsigned int i = 0; i<edges[toAmputate].size(); i++){
        if (edges[toAmputate][i]==1) remove_edge(toAmputate, (int)i);
    }
}
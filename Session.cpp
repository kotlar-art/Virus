
#include "Session.h"
#include <fstream>
#include <iostream>
using json = nlohmann::json;
using namespace std;
//constructor
Session::Session(const std::string& path):g(), treeType(Root),infectedList(),agents(), cycle(0){
    ifstream i("path");
    json j;
    j << i;
    Graph g(j["Graph"]);
    if (j["tree"] == "M") {
        treeType = MaxRank;
    } else if (j["tree"] == "C") {
        treeType = Cycle;
    }
    for(auto& elem: j["agents"]){
        if(elem[0] == 'C'){
            addAgent(ContactTracer());
        }
        else{
            addAgent(Virus(elem[1]));
        }
    }
}

//copy constructor
Session::Session(const Session& session):g(session.getGraph()), treeType(session.getTreeType()), infectedList(session.infectedList),agents(), cycle(session.cycle) {
    for (int i = 0; i < session.agents.size(); ++i) {
        agents.push_back(agents[i]->clone());
    }
}

//destructor
Session::~Session() {clear();}

//copy assignment operator
const Session &Session::operator=(const Session &other) {
    if(this == &other){
        return *this;
    }
    clear();
    cycle = other.cycle;
    infectedList = other.infectedList;
    g = other.g;
    treeType = other.getTreeType();
    for(auto& elem: other.agents){
        addAgent(elem->clone());
    }
    return *this;
}


//move constructor

Session::Session(Session &&other) {
    cycle = other.cycle;
    infectedList = other.infectedList;
    g = other.g;
    treeType = other.getTreeType();
    agents = other.agents;
    other.agents.clear();
}

//move assignment operator
const Session &Session::operator=(Session &&other) {
    clear();
    cycle = other.cycle;
    infectedList = other.infectedList;
    g = other.g;
    treeType = other.getTreeType();
    agents = other.agents;
    other.agents.clear();
    return *this;
}


const Graph& Session::getGraph() const {
    return g;
}


void Session::setGraph(const Graph &graph) {
    vector<vector<int>> k(graph.getEdges());
    g.set_graph(graph.getEdges());
}

//void Session::simulate() {
//    int cycle = 0;
//    while (!toTerminate()) {
//
//        cycle++;
//    }
//}


TreeType Session::getTreeType() const {return treeType;}

void Session::enqueueInfected(int a) {
    infectedList.push_back(a);
    g.infectNode(a);
}

int Session::dequeueInfected() {
    int k = infectedList[0];
    infectedList.erase(infectedList.begin());
    return k;
}

void Session::addAgent(const Agent &agent) {
    Agent* clone = agent.clone();
    agents.push_back(clone);
}

int Session::getListSize() const {
    return infectedList.size();
}

bool Session::toTerminate() {
    bool toTerminate = true;
    vector<bool> list = g.getList();





    return toTerminate;
}

void Session::clear() {
    for(auto& elem: agents){
        delete elem;
    }
    agents.clear();
}

void Session::addAgent(Agent *agent) {
    agents.push_back(agent);
}

int Session::getCycle() {
    return cycle;
}












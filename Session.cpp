
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

Session::Session(const Session& session):g(session.getGraph()), treeType(session.getTreeType()), infectedList(session.infectedList),agents(),
                                                        cycleCounter(session.cycleCounter), virusSpread(session.virusSpread){
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
    cycleCounter = other.cycleCounter;
    virusSpread = other.virusSpread;
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

int Session::getCycle() const {
    return cycleCounter;
}


void Session::setGraph(const Graph &graph) {
    vector<vector<int>> k(graph.getEdges());
    g.set_graph(graph.getEdges());
}

void Session::virusHasSpread() {
    virusSpread=true;
}

void Session::simulate() {
    virusSpread = true;
    cycleCounter = 0;
    while(virusSpread){
        virusSpread = false;
        int k = agents.size();
        for (int i = 0; i < k; ++i) {
            agents[i]->act(*this);
        }
        cycleCounter++;
    }
}


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

void Session::clear() {
    for(auto& elem: agents){
        delete elem;
    }
    agents.clear();
}

void Session::addAgent(Agent *agent) {
    agents.push_back(agent);
}

bool Session::isInfectedListEmpty() {
    return infectedList.empty();
}











//
// Created by spl211 on 08/11/2020.
//

#include "Agent.h"

Agent::Agent(){}
//Virus
Virus::Virus(int nodeInd):nodeInd(nodeInd) {}
Virus::Virus(Virus const &virus):nodeInd(virus.getInd()){}
int Virus::getInd() const {return nodeInd;}
Virus * Virus::clone() const {
    return new Virus(nodeInd);
}
void Virus::act(Session &session) {
    Graph k = session.getGraph();
    std::vector<vector<int>> vec = session.getGraph().getInfo();
    bool added = false;
    for (int i = 0; i < vec[nodeInd].size() && !added; ++i) {
        if(vec[nodeInd][i] == 1 && !k.isInfected(i)){
            Virus newVirus = Virus(i);
            session.addAgent(newVirus);
            added = true;
        }
    }
    if(!k.isInfected(nodeInd)){
        session.enqueueInfected(nodeInd);
    }
}

//ContactTracer
ContactTracer::ContactTracer() {}
ContactTracer * ContactTracer::clone() const {
    return new ContactTracer();
}
void ContactTracer::act(Session &session) {
    if(session.getListSize() == 0){
        return;
    }
    TreeType treeType = session.getTreeType();
    int a = session.dequeueInfected();

}
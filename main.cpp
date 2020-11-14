#include <iostream>
#include "Session.h"

using namespace std;

int main(int argc, char** argv){
    vector<vector<int>> edges = {{0,1,0,0,1,0,0,0,0},
                                 {1,0,1,1,0,1,1,0,0},
                                 {0,1,0,1,0,1,0,0,0},
                                 {0,1,1,0,0,1,0,0,0},
                                 {1,0,0,0,0,1,0,0,0},
                                 {0,1,1,1,1,0,0,1,0},
                                 {0,1,0,0,0,0,0,1,1},
                                 {0,0,0,0,0,1,1,0,0},
                                 {0,0,0,0,0,0,1,0,0}};
    vector<Agent*> vec;
    vec.push_back(new Virus(0));
    vec.push_back(new ContactTracer());
    Graph g(edges);
    Session session(g,vec,Cycle);
    session.simulate();
}

//int main(int argc, char** argv){
//    if(argc != 2){
//        cout << "usage cTrace <config_path>" << endl;
//        return 0;
//    }
//    Session sess(argv[1]);
//    sess.simulate();
//    return 0;
//}
cmake_minimum_required(VERSION 3.17)
project(AssignmentOne)

set(CMAKE_CXX_STANDARD 14)

add_executable(AssignmentOne main.cpp Graph.cpp Graph.h Tree.cpp Tree.h Session.cpp Session.h json.hpp Agent.cpp Agent.h CycleTree.cpp RootTree.cpp MaxRankTree.cpp)
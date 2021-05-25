cmake_minimum_required(VERSION 3.19)
project(LP2)

set(CMAKE_CXX_STANDARD 14)

include_directories(/opt/ibm/ILOG/CPLEX_Studio201/cplex/include/)
include_directories(/opt/ibm/ILOG/CPLEX_Studio201/concert/include/)

add_executable(LP2 main.cpp AlgoByJoachimAndKamyar.h AlgoByJoachimAndKamyar.cpp BFS.h BFS.cpp bipartitroundingForCharikar.h bipartitroundingForCharikar.cpp CharLiKUFL.h CharLiKUFL.cpp evaluate.h evaluate.cpp fixedDouble.h fixedDouble.cpp kMSolution.h kMSolution.cpp loadsave.h loadsave.cpp roundgraph.h)
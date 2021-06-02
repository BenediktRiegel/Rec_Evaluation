#!/bin/sh

Data_Path="${PWD}/Data/Wikipedia/"
LP_Path="${PWD}/new_versions/LP/"
kUFL_Path="${PWD}/new_versions/kUFL_LocalSearch/"
Rec_Path="${PWD}/new_versions/Rec_LocalSearch/"

./new_versions/LP/LP_Algo ${Data_Path} 20 >> ${LP_Path}normal_wikipedia.out &
./new_versions/kUFL_LocalSearch/kUFL_LocalSearch ${Data_Path} 20 >> ${kUFL_Path}normal_wikipedia.out &
./new_versions/Rec_LocalSearch/RecLocalSearchEval ${Data_Path} 20 >> ${Rec_Path}normal_wikipedia.out &

#!/bin/sh

Data_Path="${PWD}/Data/Congress/"
LP_Path="${PWD}/new_versions/LP/"
kUFL_Path="${PWD}/new_versions/kUFL_LocalSearch/"
Rec_Path="${PWD}/new_versions/Rec_LocalSearch/"

./new_versions/LP/LP_Algo ${Data_Path} 20 >> ${LP_Path}output.out &
./new_versions/kUFL_LocalSearch/kUFL_LocalSearch ${Data_Path} 20 >> ${kUFL_Path}output.out &
./new_versions/Rec_LocalSearch/RecLocalSearchEval ${Data_Path} 20 >> ${Rec_Path}output.out &

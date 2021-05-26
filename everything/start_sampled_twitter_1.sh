#!/bin/sh

Data_Path="${PWD}/Data/Twitter/"
LP_Path="${PWD}/sample/sample_LP/"
kUFL_Path="${PWD}/sample/sample_kUFL_LocalSearch/"
Rec_Path="${PWD}/sample/sample_Rec_LocalSearch/"

./sample/sample_LP/sample_LP_Algo ${Data_Path} 1 1 >> ${LP_Path}sample1_twitter.out &
./sample/sample_kUFL_LocalSearch/sample_kUFL_LocalSearch ${Data_Path} 1 1 >> ${kUFL_Path}sample1_twitter.out &
./sample/sample_Rec_LocalSearch/sample_RecLocalSearchEval ${Data_Path} 1 1 >> ${Rec_Path}sample1_twitter.out &

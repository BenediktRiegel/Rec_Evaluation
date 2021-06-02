#!/bin/sh

Data_Path="${PWD}/Data/Twitter/"
#LP_Path="${PWD}/Twitter_sample/Twitter_sample_LP/"
kUFL_Path="${PWD}/Twitter_sample/Twitter_sample_kUFL_LocalSearch/"
Rec_Path="${PWD}/Twitter_sample/Twitter_sample_Rec_LocalSearch/"

./Twitter_sample/Twitter_sample_kUFL_LocalSearch/Twitter_sample_kUFL_LocalSearch ${Data_Path} 1 >> ${kUFL_Path}sample_twitter.out &
./Twitter_sample/Twitter_sample_Rec_LocalSearch/Twitter_sample_RecLocalSearchEval ${Data_Path} 1 >> ${Rec_Path}sample_twitter.out &

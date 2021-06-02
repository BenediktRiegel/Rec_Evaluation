#!/bin/sh

Data_Path="${PWD}/Data/Twitter/"
LP_Path="${PWD}/new_versions/LP/"
kUFL_Path="${PWD}/new_versions/kUFL_LocalSearch/"
Rec_Path="${PWD}/new_versions/Rec_LocalSearch/"

./new_versions/kUFL_LocalSearch/kUFL_LocalSearch ${Data_Path} 1 >> ${kUFL_Path}full_twitter.out &
./new_versions/Rec_LocalSearch/RecLocalSearchEval ${Data_Path} 1 >> ${Rec_Path}full_twitter.out &

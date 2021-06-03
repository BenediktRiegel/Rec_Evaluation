#!/bin/sh

Data_Path="${PWD}/Data/Twitter/"
#LP_Path="${PWD}/Twitter_sample/Twitter_sample_LP/"
kUFL_Path="${PWD}/Twitter_byte_sample/Twitter_byte_sample_kUFL_LocalSearch/"
Rec_Path="${PWD}/Twitter_byte_sample/Twitter_byte_sample_Rec_LocalSearch/"

./Twitter_byte_sample/Twitter_byte_sample_kUFL_LocalSearch/Twitter_byte_sample_kUFL_LocalSearch ${Data_Path} 10 0 500 >> ${kUFL_Path}byte_sample_twitter.out &
./Twitter_byte_sample/Twitter_byte_sample_Rec_LocalSearch/Twitter_byte_sample_RecLocalSearchEval ${Data_Path} 10 0 500 >> ${Rec_Path}byte_sample_twitter.out &

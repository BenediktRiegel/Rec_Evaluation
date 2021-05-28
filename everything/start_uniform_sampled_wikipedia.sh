#!/bin/sh

Data_Path="${PWD}/Data/Wikipedia/"
LP_Path="${PWD}/uniform_sampling/uniform_sampling_LP/"
kUFL_Path="${PWD}/uniform_sampling/uniform_sampling_kUFL_LocalSearch/"
Rec_Path="${PWD}/uniform_sampling/uniform_sampling_Rec_LocalSearch/"

./uniform_sampling/uniform_sampling_LP/uniform_sampling_LP_Algo ${Data_Path} 1 >> ${LP_Path}uniform_sampled_wikipedia.out &
./uniform_sampling/uniform_sampling_kUFL_LocalSearch/uniform_sampling_kUFL_LocalSearch ${Data_Path} 1 >> ${kUFL_Path}uniform_sampled_wikipedia.out &
./uniform_sampling/uniform_sampling_Rec_LocalSearch/uniform_sampling_RecLocalSearchEval ${Data_Path} 1 >> ${Rec_Path}uniform_sampled_wikipedia.out &

#!/bin/sh

Data_Path="${PWD}/Data/lower_dimensions_Wikipedia/"
LP_Path="${PWD}/uniform_sampling/uniform_sampling_LP/"
kUFL_Path="${PWD}/uniform_sampling/uniform_sampling_kUFL_LocalSearch/"
Rec_Path="${PWD}/uniform_sampling/uniform_sampling_Rec_LocalSearch/"

./uniform_sampling/uniform_sampling_LP/uniform_sampling_LP_Algo ${Data_Path} 1 >> ${LP_Path}uniform_sample_lower_dimensions_Wikipedia.out &
./uniform_sampling/uniform_sampling_kUFL_LocalSearch/uniform_sampling_kUFL_LocalSearch 1 ${Data_Path} >> ${kUFL_Path}uniform_sample_lower_dimensions_Wikipedia.out &
./uniform_sampling/uniform_sampling_Rec_LocalSearch/uniform_sampling_RecLocalSearchEval 1 ${Data_Path} >> ${Rec_Path}uniform_sample_lower_dimensions_Wikipedia.out &

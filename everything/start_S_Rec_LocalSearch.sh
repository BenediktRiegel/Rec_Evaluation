#!/bin/sh

Data_Path="${PWD}/Data/Congress/"
startS_Rec_Path="${PWD}/startS_RecLocalSearch/"
comparekUFL_Path="kUFLLocalSearch"
compareLP_Path="LP"

./startS_RecLocalSearch/startS_RecLocalSearchEval ${Data_Path} ${comparekUFL_Path} 10 >> ${startS_Rec_Path}startS_Rec_kUFL_output.out &
./startS_RecLocalSearch/startS_RecLocalSearchEval ${Data_Path} ${compareLP_Path} 10 >> ${startS_Rec_Path}startS_Rec_LP_output.out &

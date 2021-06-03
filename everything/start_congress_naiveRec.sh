#!/bin/sh

Data_Path="${PWD}/Data/Congress/"
naiveRec_Path="${PWD}/naiveRec/"
comparekUFL_Path="/EvaluationResults/kUFLLocalSearch/compareNaiveRec/"
compareLP_Path="/EvaluationResults/LP/compareNaiveRec/"

./naiveRec/naive_RecLocalSearchEval ${Data_Path} ${comparekUFL_Path} 10 16 >> ${naiveRec_Path}LP_output.out &
./naiveRec/naive_RecLocalSearchEval ${Data_Path} ${compareLP_Path} 10 16 >> ${naiveRec_Path}kUFL_output.out &

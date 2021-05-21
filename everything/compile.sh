#Normal
make -C ./Source_code/kUFL_LocalSearch/ all
cp ./Source_code/kUFL_LocalSearch/kUFL_LocalSearch ./new_versions/kUFL_LocalSearch/
chmod +x ./new_versions/kUFL_LocalSearch/

make -C ./Source_code/LP2/ all
cp ./Source_code/LP2/LP_Algo ./new_versions/LP/
chmod +x ./new_versions/LP/

make -C ./Source_code/Rec_LocalSearch/ all
cp ./Source_code/Rec_LocalSearch/RecLocalSearchEval ./new_versions/Rec_LocalSearch/
chmod +x ./new_versions/Rec_LocalSearch/


#Sample
make -C ./Source_code/sample_kUFL_LocalSearch/ all
cp ./Source_code/sample_kUFL_LocalSearch/sample_kUFL_LocalSearch ./sample/sample_kUFL_LocalSearch/
chmod +x ./sample/sample_kUFL_LocalSearch/

make -C ./Source_code/sample_LP2/ all
cp ./Source_code/sample_LP2/sample_LP_Algo ./sample/sample_LP/
chmod +x ./sample/sample_LP/

make -C ./Source_code/sample_Rec_LocalSearch/ all
cp ./Source_code/sample_Rec_LocalSearch/sample_RecLocalSearchEval ./sample/sample_Rec_LocalSearch/
chmod +x ./sample/sample_Rec_LocalSearch/

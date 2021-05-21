#ifndef BAALGO_ALGOBYJOACHIMANDKAMYAR_H
#define BAALGO_ALGOBYJOACHIMANDKAMYAR_H
#include "kMSolution.h"
#include <vector>
#include <map>
#include "fixedDouble.h"

using namespace std;

pair<kMSolution, vector<int>> recsolve(vector<int>* C, vector<int>* F, vector<vector<double>>* dFtoF,
vector<vector<double>>* dAtoC, double lam, int k, const vector<vector<int>>& nearest_k, const vector<int>& nearest_f);

#endif //BAALGO_ALGOBYJOACHIMANDKAMYAR_H

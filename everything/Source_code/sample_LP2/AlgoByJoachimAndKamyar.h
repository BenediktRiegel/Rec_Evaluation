#ifndef BAALGO_ALGOBYJOACHIMANDKAMYAR_H
#define BAALGO_ALGOBYJOACHIMANDKAMYAR_H
#include "kMSolution.h"
#include <vector>
#include <map>
#include "fixedDouble.h"

using namespace std;

pair<kMSolution, bool> recsolve(const vector<int>& sampled_C, vector<int>* C, vector<int>* F, map<int, map<int, double>>* dFtoF,
                                map<int, map<int, double>>* dAtoC, double lam, int k, const vector<vector<int>>& G,
                                const vector<vector<int>>& nearest_k, const vector<int>& nearest_f);

#endif //BAALGO_ALGOBYJOACHIMANDKAMYAR_H

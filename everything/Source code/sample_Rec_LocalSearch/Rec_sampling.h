#include <vector>
#include "kMSolution.h"

using namespace std;

pair<kMSolution, vector<int>> solve_rec_sample(vector<int>* C, vector<int>* F, vector<vector<double>>* dFtoF,
                                         vector<vector<double>>* dAtoC, double lam, int k,
                                         const vector<vector<int>>& nearest_k, const vector<int>& nearest_f);

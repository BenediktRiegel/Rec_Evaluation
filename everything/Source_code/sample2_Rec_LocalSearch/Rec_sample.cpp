#include "Rec_sample.h"
#include <vector>
#include "kMSolution.h"
#include "vectorRec_LocalSearch.h"
#include <iostream>
#include <set>

using namespace std;

pair<kMSolution, vector<int>> rec_solve(const vector<int>& sampled_C, vector<int>* C, vector<int>* F, vector<vector<double>>* dFtoC, int k, double lam,
                                        vector<vector<double>>* dFtoF, const vector<vector<int>>& nearest_k, const vector<int>& nearest_f){

    kMSolution S;
    S.service_cost = -1;
    S.other_cost = -1;
    int indexM = 0;
    int maxM = (*F).size();

    vector<int> itr;
#pragma omp declare reduction(minKMS : kMSolution : omp_out = (omp_out.service_cost == -1 || (omp_in.cost() < omp_out.cost())) ? omp_in : omp_out) initializer (omp_priv=omp_orig)
#pragma omp parallel for reduction(minKMS:S)
    for (int p = 0; p < (*F).size(); ++p) {
        int m = (*F).at(p);
        indexM += 1;
        cout << "JKRedAlgo: " << indexM << " of " << maxM << endl;

        vector<int> Fsubvec;
        // Get Fsubvec and newC
        {
            set<int> Fsubset;
            //cout << "Fsubset.insert k nearest for m" << endl;
            for (int i = 0; i < k; ++i) {
                Fsubset.insert(nearest_k.at(m).at(i));
            }
            //cout << "Fsubset.insert nearest f" << endl;
            for (int i = 0; i < sampled_C.size(); ++i) {
                Fsubset.insert(nearest_f.at(sampled_C.at(i)));
            }
            //cout << "Fset to Fvec" << endl;
            for (int el : Fsubset) {
                Fsubvec.push_back(el);
            }
        }
        cout << "C.size(): " << (*C).size() << endl;
        cout << "sampled_C.size(): " << sampled_C.size() << endl;
        cout << "Fsubvec.size(): " << Fsubvec.size() << endl;
        pair<kMSolution, int> SAndItr = localsearchRec(C, &Fsubvec, dFtoC, k, lam, dFtoF);

        kMSolution tempS = SAndItr.first;
#pragma omp critical
        {
            itr.push_back(SAndItr.second);
        }
        // print out the facilities of the solution and what the costs are for the used median
        cout << "m: " << m << " tempCost: " << stringValue(tempS.cost()) << endl;
        // check, if this solution is better than previous solutions
        if (S.service_cost == -1 || tempS.cost() < S.cost()) {
            S = tempS;
            //cout << "newCost: " << stringValue(S.cost()) << endl;
        }
    }

    return pair<kMSolution, vector<int>> (S, itr);
}

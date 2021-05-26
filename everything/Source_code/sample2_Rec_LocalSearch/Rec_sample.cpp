#include "Rec_sample.h"
#include <vector>
#include "kMSolution.h"
#include "vectorRec_LocalSearch.h"
#include <iostream>
#include <set>

using namespace std;

pair<kMSolution, vector<int>> rec_solve(vector<int>* C, vector<int>* F, vector<vector<double>>* dFtoC, int k, double lam,
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
        vector<int> newC;
        // Get Fsubvec and newC
        {
            set<int> Fsubset;
            set<int> Cset;
            //cout << "Fsubset.insert k nearest for m" << endl;
            //cout << "Csets.insert k nearest for m" << endl;
            for (int i = 0; i < k; ++i) {
                Fsubset.insert(nearest_k.at(m).at(i));
                Cset.insert(nearest_k.at(m).at(i));
            }
            //cout << "Fsubset.insert nearest f" << endl;
            //cout << "Csets.insert nearest f" << endl;
            for (int i = 0; i < (*C).size(); ++i) {
                Fsubset.insert(nearest_f.at((*C).at(i)));
                Cset.insert(nearest_f.at((*C).at(i)));
            }
            //cout << "Cset.insert every client" << endl;
            for (int el : *C) {
                Cset.insert(el);
            }
            //cout << "Fset to Fvec" << endl;
            for (int el : Fsubset) {
                Fsubvec.push_back(el);
            }
            //cout << "Cset to Cvec" << endl;
            for (int el : Cset) {
                newC.push_back(el);
            }
        }
        cout << "newC.size(): " << newC.size() << endl;
        cout << "Fsubvec.size(): " << Fsubvec.size() << endl;
        pair<kMSolution, int> SAndItr = localsearchRec(&newC, &Fsubvec, dFtoC, k, lam, dFtoF);

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

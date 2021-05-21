#include "Rec_sampling.h"
#include <iostream>
#include <vector>
#include <set>
#include "kMSolution.h"
#include "vectorRec_LocalSearch.h"

using namespace std;

pair<kMSolution, vector<int>> solve_rec_sample(vector<int>* C, vector<int>* F, vector<vector<double>>* dFtoF,
                                       vector<vector<double>>* dAtoC, double lam, int k,
                                       const vector<vector<int>>& nearest_k, const vector<int>& nearest_f) {
    cout << "start recsolve" << endl;
    kMSolution S;
    S.service_cost = -1;
    S.other_cost = -1;
    int indexM = 0;
    int maxM = (*F).size();
    vector<int> itr;
    // guessing the median in F
    cout << "guessing median in F" << endl;
#pragma omp declare reduction(minKMS : kMSolution : omp_out = (omp_out.service_cost == -1 || (omp_in.cost() < omp_out.cost())) ? omp_in : omp_out) initializer (omp_priv=omp_orig)
#pragma omp parallel for reduction(minKMS:S)
    for (int m : *F) {
        indexM += 1;
        // JKRedAlgo = Joachim and Kamyar Reduction Algorithm
        // print the number of the median guessed
        cout << "JKRedAlgo: " << indexM << " of " << maxM << endl;
        // time_t start = time(nullptr);
        vector<int> Fsubvec;
        vector<int> newC;
        // Get Fsubvec and newC
        {
            set<int> Fsubset;
            set<int> Cset;
            for (int i = 0; i < k; ++i) {
                Fsubset.insert(nearest_k.at(m).at(i));
                Cset.insert(nearest_k.at(m).at(i));
            }
            for (int i = 0; i < (*C).size(); ++i) {
                Fsubset.insert(nearest_f.at((*C).at(i)));
                Cset.insert(nearest_f.at((*C).at(i)));
            }
            for (int el : *C) {
                Cset.insert(el);
            }
            for (int el : Fsubset) {
                Fsubvec.push_back(el);
            }
            for (int el : Cset) {
                newC.push_back(el);
            }
        }
        pair<kMSolution, int> SAndItr = localsearchRec(&newC, &Fsubvec, dAtoC, k, lam, dFtoF);

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
    /*
    for (int i = 1; i < S.solution.size(); ++i) {
        cout << ", " << S.solution[i];
    }
    cout << "]" << endl;
     */

    return pair<kMSolution, vector<int>> (S, itr);
}

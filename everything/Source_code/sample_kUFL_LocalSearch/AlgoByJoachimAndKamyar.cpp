#include "AlgoByJoachimAndKamyar.h"
#include <iostream>
#include <vector>
#include "kMSolution.h"
#include <set>
//#include "CharLiKUFL.h"
#include "vectorEkUFL_LocalSearch.h"
#include <omp.h>
#include "fixedDouble.h"

using namespace std;

double calculate_RCcost(const vector<int>& S, vector<vector<double>>* dFtoF, double lam) {
    //fixedDouble cost = fixedDouble("0");
    double cost = 0;
    for (int i1 = 0; i1 < S.size(); ++i1) {
        for (int i2 = i1 + 1; i2 < S.size(); ++i2) {
            cost += (*dFtoF).at(S.at(i1)).at(S.at(i2));
        }
    }
    cost = cost * lam;
    return cost;
}

pair<kMSolution, vector<int>> recsolve(vector<int>* C, vector<int>* F, vector<vector<double>>* dFtoF,
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
    for (int p = 0; p < (*F).size(); ++p) {
        int m = (*F).at(p);
        indexM += 1;
        // JKRedAlgo = Joachim and Kamyar Reduction Algorithm
        // print the number of the median guessed
        cout << "JKRedAlgo: " << indexM << " of " << maxM << endl;
        // time_t start = time(nullptr);
        vector<double> f;
        // calculate the opening cost of each i in F
        for (int i : *F) {
            f.push_back(((k - 1) * lam * (*dFtoF).at(i).at(m)));
        }
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
        pair<kMSolution, int> SAndItr = localsearchkUFL(&newC, &Fsubvec, dAtoC, k, &f);

        kMSolution tempS = SAndItr.first;
#pragma omp critical
        {
            itr.push_back(SAndItr.second);
        }
        tempS.other_cost = calculate_RCcost(tempS.solution, dFtoF, lam);
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

/*
kMSolution recsolve(vector<int>* C, vector<int>* F, map<int, map<int, double>>* dFtoF, 
    map<int, map<int, double>>* dAtoC, double lam, int k, const vector<vector<int>>& G){

    kMSolution S;
    S.service_cost = -1;
    S.other_cost = -1;
    int indexM = 0;
    int maxM = (*F).size();
// guessing the median in F
    for (int m : *F) {
            indexM += 1;
            // JKRedAlgo = Joachim and Kamyar Reduction Algorithm
            // print the number of the median guessed
            cout << "JKRedAlgo: " << indexM << " from " << maxM << endl;
            // time_t start = time(nullptr);
            map<int, double> f;
            // calculate the opening cost of each i in F
            for (int i : *F) {
                f[i] = ((k - 1.0) * lam * (*dFtoF)[i][m]);
            }

            // print('(k - 1) * lam * dFtoF[i, m] = ' + str(k-1) + ' * ' + str(lam) + ' * ' + str(dFtoF[i, m]) + ' = ' + str((k - 1) * lam * dFtoF[i, m]))

            // use localSearch or Charikar/Li Algo, depending on which is wanted

            //if LocalSearch:
            //    (tempS, tempCost) = LocalSearchkUFL.solve(C, F, k, dFtoC, f)
            //else:

            kMSolution tempS = solvekUFL(C, F, dAtoC, k, &f, G);

            tempS.other_cost = calculate_RCcost(tempS.solution, dFtoF, lam);
            // print out the facilities of the solution and what the costs are for the used median
            cout << "m: " << m << " tempCost: " << tempS.cost() << endl;
            // check, if this solution is better than previous solutions
            if (S.service_cost == -1 || tempS.cost() < S.cost()) {
                S = tempS;
                cout <<"newCost: " << S.cost() << endl;
            }
    }
// if we used Charikar/Li, ten write the time to a file and print it
    //if not LocalSearch:

    //long total = time(nullptr) - start;
    //writeTimeToFile(total, lam, k, len(C), LocalSearch)
    //print('time: ' + str(total))
    //cout << "\n\nBEST S:\n\tcost:\t" << S.cost() << "\n\tsolution:\t[" << S.solution[0];
    for (int i = 1; i < S.solution.size(); ++i) {
        cout << ", " << S.solution[i];
    }
    cout << "]" << endl;

    return S;
}
*/

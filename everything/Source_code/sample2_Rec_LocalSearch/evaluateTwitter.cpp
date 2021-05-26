#include "evaluateTwitter.h"
#include <iostream>
#include <chrono>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "kMSolution.h"
#include "loadsave.h"
#include "Rec_sample.h"
#include "fixedDouble.h"
#include "SampleData.h"

using namespace std;


void saveResult(string path, kMSolution S, vector<int> itr, double duration, double lam, int k, const vector<int>& C) {
	string filepath = path + "sampleEvaluationResults/RecLocalSearch/k=" + stringValue(k) + "_lam=" + stringValue(lam) + ".txt";
	cout << path << endl;
	string result;
	result += "S=";
	string solString = "[" + to_string(S.solution.at(0));
	for (int i = 1; i < S.solution.size(); ++i) {
		solString += "," + to_string(S.solution.at(i));
	}
    solString += "]_serviceCost=" + to_string(S.service_cost) + "_otherCost=" + to_string(S.other_cost) + "_duration=" + to_string(duration) + "ms_itr=";
    solString += to_string(itr.at(0));
    for (int i = 1; i < itr.size(); ++i) {
        solString += "," + to_string(itr.at(i));
    }
    result += solString + "_Clients=" + to_string(C.at(0));
    string c_string = "";
    for (int i = 1; i < C.size(); ++i) {
        c_string += "," + to_string(C.at(i));
    }
    result += c_string + "\n";

	cout << "save" << endl;
	fstream file;
	cout << filepath << endl;
	file.open(filepath, ios_base::app);
	file << result;
    cout << "done saving" << endl;
}


void evalTwitter(string path, int num_runs, int version) {
	cout << "Starting evalTwitter" << endl;
	//Remember F <= C (subset equal) and F = [0, |F|)
	cout << path << endl;
	cout << "read data" << endl;
	string kpath = path + "k.txt";
	vector<int> ks = getIntVector(kpath);
	string lampath = path + "lam.txt";
	vector<double> lams = getDoubleVector(lampath);
	string FtoCpath = path + "full_dAtoC.txt";
	vector<vector<double>> dAtoC = getDistanceVector(FtoCpath);
    vector<vector<int>> nearest_k = getIntVecVec(path + "nearest_k.txt");
    vector<int> nearest_f = getIntVector(path + "nearest_f.txt");
    //vector<vector<int>> G = getGraphVector(path + "G.txt");
	
	cout << "Read C and F" << endl;
	vector<int> sampled_C = getIntVector(path + "translated_sampled_C.txt");
    vector<int> sample_amounts = {(int)sampled_C.size()};
    if (version <= 1) {
        sample_amounts = getIntVector(path + "sample_amounts.txt");
    }

	//Since AtoC is only FtoC
	string Fpath = path + "F.txt";
	vector<int> F = getIntVector(Fpath);

    cout << "nearest_f.size(): " << nearest_f.size() << endl;
    cout << "nearest_k.size(): " << nearest_k.size() << endl;
    cout << "F.size(): " << F.size() << endl;
    cout << "sampled_C.size(): " << sampled_C.size() << endl;
    cout << "test" << endl;
    cout << "sample_amounts.size(): " << sample_amounts.size() << endl;
    cout << "dAtoC.size(): " << dAtoC.size() << endl;
    for (int run = 0; run < num_runs; ++run) {
        cout << "run " << run << endl;
        for (int amount : sample_amounts) {
            cout << "num_to_be_sampled: " << amount << endl;
            vector<int> C = fullMatrix_D_sampling(sampled_C, dAtoC, amount);
            for (int k : ks) {
                for (double lam : lams) {
                    cout << "k: " << k << ", lam: " << stringValue(lam) << "C.size(): " << C.size() << endl;
                    auto t_start = std::chrono::high_resolution_clock::now();
                    pair<kMSolution, vector<int>> SandItr = rec_solve(&C, &F, &dAtoC, k, lam, &dAtoC, nearest_k, nearest_f);
                    //pair<kMSolution, int> SandItr = rec_solve(&C, &F, &dAtoC, k, lam, &dAtoC);
                    auto t_end = std::chrono::high_resolution_clock::now();
                    double duration = std::chrono::duration<double, std::milli>(t_end - t_start).count();

                    saveResult(path, SandItr.first, SandItr.second, duration, lam, k, C);
                }
            }
        }
        cout << "end run " << run << "\n\n\n" << endl;
    }
    /* LP rounding
    string Gpath = path + "sortedTwitter.txt";
    vector <vector<int>> G = getGraphVector(Gpath);
    cout << "start LP rounding evalutaion" << endl;
    for (int k : ks) {
        for (double lam : lams) {
            cout << "k: " << k << ", lam: " << lam << endl;
            auto t_start = std::chrono::high_resolution_clock::now();
            kMSolution S = (recsolve(&C, &F, &dFtoF, &dAtoC, lam, k, G));
            auto t_end = std::chrono::high_resolution_clock::now();
            double duration = std::chrono::duration<double, std::milli>(t_end - t_start).count();

            saveResult(path, S, duration, lam, k);
        }
    }
    */

}

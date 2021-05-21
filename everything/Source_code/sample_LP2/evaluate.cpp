#include "evaluate.h"
#include <iostream>
#include <chrono>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "kMSolution.h"
#include "loadsave.h"
#include "AlgoByJoachimAndKamyar.h"
#include "fixedDouble.h"

using namespace std;


void saveResult(string path, kMSolution S, bool lp_only, double duration, double lam, int k) {
	string filepath = path + "sampleEvaluationResults/LP/k=" + to_string(k) + "_lam=" + to_string(lam) + ".txt";
	cout << "saving to " << filepath << endl;
	string result;
	result += "S=";
	string solString = "[" + to_string(S.solution.at(0));
	for (int i = 1; i < S.solution.size(); ++i) {
		solString += "," + to_string(S.solution.at(i));
	}
	solString += "]_serviceCost=" + to_string(S.service_cost) + "_otherCost=" + to_string(S.other_cost) + "_duration=" + to_string(duration) + "ms_lpOnly=" + to_string(lp_only);
	result += solString + "\n";

	fstream file;
	file.open(filepath, ios_base::app);
	file << result;
	file.close();
	cout << "done saving" << endl;
}


void evalFpartC(string path, int num_runs) {
	cout << "Starting evalFpartC" << endl;
	//Remember F <= C (subset equal) and F = [0, |F|)
	cout << "read data" << endl;
	map<int, map<int, double>> dAtoC = getDistanceMap(path + "dAtoC.txt");
    cout << "read G" << endl;
	vector<vector<int>> G = getGraphVector(path + "G.txt");
	//string FtoFpath = path + "dFtoF.txt";
	//map<int, map<int, double>> dFtoF = getDistanceMap(FtoFpath);

	cout << "Create C and F" << endl;
	vector<int> C = getIntVector(path + "sampled_C.txt");

	vector<int> F = getIntVector(path + "F.txt");

	vector<int> ks = getIntVector(path + "k.txt");

	vector<double> lams = getDoubleVector(path + "lam.txt");
	cout << "read nearest_k.txt" << endl;
    vector<vector<int>> nearest_k = getIntVecVec(path + "nearest_k.txt");
    cout << "read nearest_f.txt" << endl;
    vector<int> nearest_f = getIntVector(path + "nearest_f.txt");

	/*
	for (int c : C){
		for (int c2 : C) {
			if (dAtoC.at(c).at(c2) < 0) {
				cout << "dAtoC[" << c << ", " << c2 << "] = " << dAtoC.at(c).at(c2) << endl;
			}
		}
	}*/

	cout << "start evalutaion" << endl;
	for (int k : ks) {
		for (double lam : lams) {
			cout << "k: " << k << ", lam: " << stringValue(lam) << endl;
			for (int run = 0; run < num_runs; ++run) {
				cout << "run " << run << endl;
				auto t_start = std::chrono::high_resolution_clock::now();
				pair<kMSolution, bool> S = (recsolve(&C, &F, &dAtoC, &dAtoC, lam, k, G, nearest_k, nearest_f));
				auto t_end = std::chrono::high_resolution_clock::now();
				double duration = std::chrono::duration<double, std::milli>(t_end - t_start).count();

				saveResult(path, S.first, S.second, duration, lam, k);
				if (S.second) {
					cout << "Everything was LP_only" << endl;
					break;
				}
			}
			cout << "runs finished\n\n\n" << endl;
		}
	}
	cout << "Done" << endl;


}


void evalTwitter(string path, int num_runs) {
	cout << "Starting evalTwitter" << endl;
	//Remember F <= C (subset equal) and F = [0, |F|)
	cout << "read data" << endl;
	vector<int> ks = getIntVector(path + "k.txt");
	vector<double> lams = getDoubleVector(path + "lam.txt");
	string FtoCpath = path + "dFtoC.txt";
	map<int, map<int, double>> dAtoC = getDistanceMap(FtoCpath);
	string Gpath = path + "sortedTwitter.txt";
	vector<vector<int>> G = getGraphVector(Gpath);
	string FtoFpath = path + "dFtoF.txt";
	map<int, map<int, double>> dFtoF = getDistanceMap(FtoFpath);
    vector<vector<int>> nearest_k = getIntVecVec(path + "nearest_k.txt");
    vector<int> nearest_f = getIntVector(path + "nearest_f.txt");

	cout << "Create C and F" << endl;
	vector<int> C = getIntVector(path + "sampled_C.txt");
	/*
	C.reserve(dAtoC[0].size());
	for (int i = 0; i < dAtoC[0].size(); ++i) {
		C.push_back(i);
	}
	*/
	vector<int> F = getIntVector(path + "F.txt");

	cout << "start evalutaion" << endl;
	for (int run = 0; run < num_runs; ++run) {
		cout << "run " << run << endl;
		for (int k : ks) {
			for (double lam : lams) {
				cout << "k: " << k << ", lam: " << stringValue(lam) << endl;
				auto t_start = std::chrono::high_resolution_clock::now();
				pair<kMSolution, bool> S = (recsolve(&C, &F, &dFtoF, &dAtoC, lam, k, G, nearest_k, nearest_f));
				auto t_end = std::chrono::high_resolution_clock::now();
				double duration = std::chrono::duration<double, std::milli>(t_end - t_start).count();
	
				saveResult(path, S.first, S.second, duration, lam, k);
			}
		}
		cout << "end run " << run << "\n\n\n" << endl;
	}


}


void evalTwitter() {
	string path = "C:/Users/Benedikt/Desktop/Uni/Bachelor/Approximationsalgorithmen/Datasets/updated/";
	evalTwitter(path, 1);
}

#include <iostream>
#include <vector>
#include "evaluate.h"
#include <string>
//#include "testChariLi.h"
//#include "fixedDouble.h"

using namespace std;


int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Exactly 4 parameters are required one is the default and the other is a path to the data and the number of runs and the fourth is the version" << endl;
        exit(1);
    }
    /*
    string path = argv[1];
    string GOrNoG = argv[2];
    vector<int> ks = { 2, 4, 8 };
    vector<double> lams;
    lams.push_back(0.0);
    double currentlam = 0.02;
    for (int i = 0; i < 7; ++i) {
        lams.push_back(currentlam / 10);
        currentlam *= 0.2;
    }
    if (GOrNoG == "1") {
        evalTwitter(path, ks, lams);
    }
    else {
        evalFpartC(path, ks, lams);
    }
    */
    //string path = "C:/Users/Benedikt/source/repos/VisBaAlgo/VisBaAlgo/TestChariLi/Twitter/";
    string path = argv[1];
    int num_runs = stoi(argv[2]);
    int version = stoi(argv[3]);
    evalFpartC(path, num_runs, version);
    //for (int i = 0; i < 8; ++i) {
    //test_ChariLi(path, 5, fixedDouble(0, 0), 0);
    //}
    //fixedDouble sol = fixedDouble(5 - 1) * fixedDouble("1.0") * 1;
    //cout << stringValue(sol) << endl;
    cout << "end\n\n\n" << endl;
    
    return 0;
}

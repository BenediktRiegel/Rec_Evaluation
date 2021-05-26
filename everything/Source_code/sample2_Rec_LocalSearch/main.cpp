#include "evaluateTwitter.h"
#include <iostream>
#include "fixedDouble.h"
#include <omp.h>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 4) {
        cout << "Exactly 4 arguments are needed, first being the default argument and the second being the path and the third is the number of runs and the fourth being the version" << endl;
        exit(1);
    }
    string path = argv[1];
    int num_runs = stoi(argv[2]);
    int version = stoi(argv[3]);
    //cout << "max threads: " << omp_get_max_threads() << endl;
    //string path = "C:/Users/Benedikt/Desktop/Uni/Bachelor/Approximationsalgorithmen/Twitter-LocalSearchOnly/TestChariLi/simple3/";
    //string path = "C:\\Users\\Benedikt\\source\\repos\\VisBaAlgo\\VisBaAlgo\\TestChariLi\\simple3\\";
    evalTwitter(path, num_runs, version);
    cout << "end\n\n\n" << endl;
    return 0;
}


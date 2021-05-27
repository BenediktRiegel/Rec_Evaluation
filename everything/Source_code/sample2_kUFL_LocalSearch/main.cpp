#include "evaluateTwitter.h"
#include <iostream>
#include "fixedDouble.h"
#include <omp.h>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 3) {
        cout << "Exactly 3 arguments are needed, first being the default argument and the second being the path and the third is the number of runs" << endl;
        exit(1);
    }
    string path = argv[1];
    int num_runs = stoi(argv[2]);
    //cout << "max threads: " << omp_get_max_threads() << endl;
    //string path = "C:\\Users\\Benedikt\\source\\repos\\VisBaAlgo\\VisBaAlgo\\TestChariLi\\medium1\\";
    //string path = "C:/Users/Benedikt/Desktop/Uni/Bachelor/Approximationsalgorithmen/Twitter-LocalSearchOnly/TestChariLi/simple3/";
    //string path = "/home/benedikt/Documents/Approx/final/sample_Rec_LocalSearch/Congress/";
    //string path = "/home/benedikt/Documents/Approx/final/Congress/";
    //int num_runs = 1;

    evalTwitter(path, num_runs);
    cout << "end\n\n\n" << endl;
    return 0;
}


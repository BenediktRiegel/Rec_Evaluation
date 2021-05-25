#include "byte_matrix.h"
#include <string>
#include <algorithm>
#include <fstream>
#include "loadsave.h"
#include "BFS.h"
#include <iostream>

using namespace std;


void printVecVec(vector<vector<int>> vecvec) {
    for (auto row : vecvec) {
        for (auto el : row) {
            cout << el << ", ";
        }
        cout << endl;
    }
}


void read_in_file_bytes(string path, int size) {
    ifstream file(path + "split_ByteM/0.txt", ios_base::in);
    for (int i = 0; i < size; ++i) {
        cout << file.get() << endl;
    }
}


vector<vector<int>> read_distance_matrix(string path, int size) {
    path += "split_ByteM/";
    int index = 0;
    vector<vector<int>> result;
    ifstream file(path + to_string(index) + ".txt", ios_base::in);
    while (file.is_open()) {
        cout << "file " << index << ".txt is open" << endl;
        vector<int> temp;
        for (int i = 0; i < size; ++i) {
            temp.push_back(file.get());
        }
        result.push_back(temp);
        file.close();

        index += 1;
        file.open(path + to_string(index) + ".txt", ios_base::in);
    }
    cout << "result.size(): " << result.size() << endl;
    //printVecVec(result);
    return result;
}


void reassemble_matrix(string path, int size) {
    string split_path = path + "split_ByteM/";
    vector<vector<int>> result;
    ofstream matrix(path + "byte_matrix.txt", ios_base::out);
    ifstream file;
    for (int i = 0; i < size; ++i) {
        //cout << "file " << i << ".txt is open" << endl;
        file.open(split_path + to_string(i) + ".txt", ios_base::in);
        if (file.is_open()) {
            for (int j = 0; j < size; ++j) {
                matrix << (char) file.get();
            }
            file.close();
        }
    }
    matrix.close();
}


void save_byte_matrix(string path) {
    cout << "read sampled_C.txt" << endl;
    vector<int> sampled_C = getIntVector(path + "sampled_C.txt");
    cout << "read G.txt" << endl;
    vector<vector<int>> G = getGraphVector(path + "G.txt");

    cout << "sort sampled_C" << endl;
    sort(sampled_C.begin(), sampled_C.end());
    int current = 1;
#pragma omp parallel for
    for (int i = 0; i < sampled_C.size(); ++i) {
        cout << current << " of " << sampled_C.size() << endl;
        current += 1;
        vector<int> distances = bfs(G, sampled_C.at(i));
        ofstream file(path + "split_ByteM/" + to_string(i) + ".txt", ios_base::out);
        for (int c : sampled_C) {
            file << (char) distances.at(c);
        }
        file.close();
    }
    reassemble_matrix(path, sampled_C.size());
}

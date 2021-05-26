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


vector<int> read_file(string path, int j, int size) {
    string split_path = path + "split_ByteM/";
    ifstream file;
    file.open(split_path + to_string(j) + ".txt", ios_base::in);
    vector<int> result;
    for (int j = 0; j < size; ++j) {
        result.push_back(file.get());
    }
    file.close();
    return result;
}


void create_fullDistancesAndNewC(const string& path, const vector<int>& sampled_C, const vector<int>& F) {
    vector<vector<int>> dAtoC = getIntVecVec(path + "dAtoC.txt");
    ofstream full_dAtoC_file(path + "full_dAtoC.txt", ios_base::out);
    for (int i = 0; i < F.size(); ++i) {
        string line = to_string(dAtoC.at(F.at(i)).at(0));
        for (int i2 = 1; i2 < F.size(); ++i2) {
            line += "," + to_string(dAtoC.at(F.at(i)).at(i2));
        }
        for (int j = 0; j < sampled_C.size(); ++j) {
            if (sampled_C.at(j) >= F.size()) {
                line += "," + to_string(dAtoC.at(F.at(i)).at(sampled_C.at(j)));
            }
        }
        line += "\n";
        full_dAtoC_file << line;
    }
    for (int j = 0; j < sampled_C.size(); ++j) {
        if (sampled_C.at(j) >= F.size()) {
            string line = to_string(dAtoC.at(F.at(0)).at(sampled_C.at(j)));
            for (int i = 1; i < F.size(); ++i) {
                line += "," + to_string(dAtoC.at(F.at(i)).at(sampled_C.at(j)));
            }
            vector<int> distances = read_file(path, j, sampled_C.size());
            for (int j2 = 0; j2 < sampled_C.size(); ++j2) {
                if (sampled_C.at(j2) >= F.size()) {
                    line += "," + to_string(distances.at(j2));
                }
            }
            line += "\n";
            full_dAtoC_file << line;
        }
    }
    full_dAtoC_file.close();

    int next = F.size();
    vector<int> translated_sampled_C;
    for (int j = 0; j < sampled_C.size(); ++j) {
        if (sampled_C.at(j) >= F.size()) {
            translated_sampled_C.push_back(next);
            next += 1;
        }
    }
    string t_sampled_C_string = to_string(translated_sampled_C.at(0));
    for (int j = 1; j < translated_sampled_C.size(); ++j) {
        t_sampled_C_string += "," + to_string(translated_sampled_C.at(j));
    }
    ofstream translated_sampled_C_file(path + "translated_sampled_C.txt", ios_base::out);
    translated_sampled_C_file << t_sampled_C_string;
    translated_sampled_C_file.close();
}


void save_byte_matrix(string path) {
    cout << "read sampled_C.txt" << endl;
    vector<int> sampled_C = getIntVector(path + "sampled_C.txt");
    vector<int> F = getIntVector(path + "F.txt");
    cout << "read G.txt" << endl;
    vector<vector<int>> G = getGraphVector(path + "G.txt");

    cout << "sort sampled_C" << endl;
    sort(sampled_C.begin(), sampled_C.end());
    cout << "sampled_C.size(): " << sampled_C.size() << endl;
    cout << "F.size(): " << F.size() << endl;
    cout << "G.size(): " << G.size() << endl;
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
    create_fullDistancesAndNewC(path, sampled_C, F);
}


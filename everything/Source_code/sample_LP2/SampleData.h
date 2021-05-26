#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> uniform_sampling(vector<int>* C, int new_amount);

vector<int> D_sampling(vector<int> old_C, const vector<vector<int>>& G, int new_amount);

vector<int> fullMatrix_D_sampling(vector<int> old_C, const map<int, map<int, double>>& dAtoC, int new_amount);

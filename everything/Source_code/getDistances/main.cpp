#include <iostream>
#include <string>
#include "byte_matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Exactly 2 arguments are needed, first being the default argument and the second being the path" << endl;
        exit(1);
    }
    string path = argv[1];
    save_byte_matrix(path);

    return 0;
}

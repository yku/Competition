#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class AmoebaDivTwo {
public:
int count(vector <string> table, int K) {
    int row = table.size();
    int col = table[0].length();
    int ret = 0;
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            int f = 0;
            if(K == 1 && table[i][j] == 'A') { ret += 1; continue; }
            for(int k = 0; k < K; k++) {
                if(j+k >= col || (j+k < col && table[i][j+k] == 'M')) f |= 1;
                if(i+k >= row || (i+k < row && table[i+k][j] == 'M')) f |= 2;
            }
            if(f == 0){ ret +=2; }
            else if(f == 1 || f == 2){ ret +=1; }
        }
    }
    return ret;
}

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

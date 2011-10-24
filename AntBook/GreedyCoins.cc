#include <iostream>
#include <algorithm>

using namespace std;

const int values[6] = { 1, 5, 10, 50, 100, 500 };

int C[6];
int A;

int solve() {
    int ret = 0;

    for(int i = 5; i >= 0; i--) {
        int t = min(A / values[i], C[i]);
        A -= t * values[i];
        ret += t;
    }

    return ret;
}

int main()
{
    C[0] = 3; C[1] = 2; C[2] = 1; C[3] = 3; C[4] = 0; C[5] = 2; A = 621;

    cout << solve() << endl;
    return 0;
}

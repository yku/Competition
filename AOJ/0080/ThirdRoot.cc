#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

double solve(int q)
{
    double x = (double)q / 2.0;
    while(fabs(x*x*x-q) >= (1e-5)*q) {
        x = x - ((x*x*x-q) / (3*x*x));
    }
    return x;
}

int main()
{
    int q;
    while(cin >> q, q != -1) {
        printf("%.6lf\n", solve(q));
    }

    return 0;
}

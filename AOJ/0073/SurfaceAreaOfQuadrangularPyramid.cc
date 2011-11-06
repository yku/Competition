#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

double solve(int x, int h)
{
    return 4.0*x*sqrt((x/2.0)*(x/2.0)+h*h)/2.0 + x*x;
}

int main()
{
    int x, h;
    while(cin >> x >> h, x || h) {
        printf("%.6lf\n", solve(x, h));
    }
    return 0;
}

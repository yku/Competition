#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    while(cin >> n, n != -1) {
        double a = 1.0, rad = 0.0;
        for(int i = 1; i < n; i++) {
            rad += asin(1.0 / sqrt(a*a+1.0));
            a = sqrt(a*a+1.0);
        }
        printf("%.2f\n%.2f\n", a*cos(rad), a*sin(rad));
    }
    return 0;
}

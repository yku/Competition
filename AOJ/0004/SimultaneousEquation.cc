#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

/*
 * AX = B
 * X = A^{-1}B
 */
void solve(double a, double b, double c, double d, double e, double f)
{
    double delta = a*e - b*d;
    double x, y;
    
    if(delta) {
        x = round(((e*c - b*f) / delta) * 1000.0) / 1000.0;
        y = round(((-d*c + a*f) / delta) * 1000.0) / 1000.0;
    }
    if(x == -0.0) x = 0.0;
    if(y == -0.0) y = 0.0;
    cout << fixed << setprecision(3);
    cout << x << " " << y << endl;
}

int main()
{
    double a, b, c, d, e, f;
    while(cin >> a >> b >> c >> d >> e >> f) {
        solve(a, b, c, d, e, f);
    }
    return 0;
}

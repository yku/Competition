#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

/**
 * ユリウス通日をもとめる
 */
int solve(int y, int m, int d)
{
    int h;
   
    if(m == 1 || m == 2) { y--; m += 12; }
    
    h = floor(365.25*(double)y) + floor(y/400) - floor(y/100) + floor(30.59 * (double)(m - 2)) + d - 678912;
    return h;
}

int zeller(int y, int m, int d)
{
    int h;
    int q = d;
    int J, K;
    
    if(m == 1 || m == 2) { m += 12; y--; }
    J = y / 100, K = y % 100; 
   
    h = (int)(q + floor((m+1) * 26 / 10) + K + floor(K/4) + floor(J/4) + 5*J) % 7;
    return h;
}

int main()
{
    int ans = 0;
    int base = solve(1900, 1, 1); // monday
    // 経過日数の差分で求める
    for(int y = 1901; y <= 2000; y++) {
        for(int m = 1; m <= 12; m++) {
            int h = (solve(y, m, 1) - base) % 7; // Monday = 0, ..., Sunday = 6
            if(h == 6) ans++; 
        }
    }
    cout << ans << endl;

    ans = 0; 
    // ツェラーの公式で求める
    for(int y = 1901; y <= 2000; y++) {
        for(int m = 1; m <= 12; m++) {
            int h = zeller(y, m, 1);
            if(h == 1) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}


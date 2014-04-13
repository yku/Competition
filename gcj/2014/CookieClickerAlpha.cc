#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;
typedef long long ll;

/**
 * 購入したほうがよいFarmの値+1を返す
 */
int getN(double C, double F, double X) {
    double f = (X-C)/C;
    f *= F;
    double dn = (f-2)/F;
    int n = (int)(dn + 0.5);
    if(n < 0) n = 0;
    
    return n;
}

double getTime(double C, double F, double X, int n)
{
    double time = 0.0;
    double rate = 2;
    // ここで(n-1)番目のFarmまで買う.0-basedなのに注意
    for(int i = 0; i < n; i++) {
        time += (C/rate);
        rate += F;
    }
    time += X/rate;
    return time;
}

int main()
{
    int T;

    cin >> T;
    for(int i = 1; i <= T; i++) {
        double C, F, X;
        double ans = 0.0; 
        cin >> C >> F >> X;
        int n = getN(C, F, X);  
        ans = getTime(C, F, X, n);
        cout << "Case #" << i << ": " << fixed << setprecision(7) << ans << endl; 
    }

    return 0;
}


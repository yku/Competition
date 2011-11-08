#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    double xa, xb, xc, xd;
    double ya, yb, yc, yd;

    while(cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd) {
        if(xa == xb) {
            if(yc == yd) cout << "YES" << endl;
            else         cout << "NO"  << endl;
        }
        else if(xc == xd) {
            if(ya == yb) cout << "YES" << endl;
            else         cout << "NO"  << endl;
        }
        else {
            double m = (yb-ya)/(xb-xa);
            double n = (yd-yc)/(xd-xc);
            // 直行条件は m * n = -1
            if(fabs(m*n+1) < 1e-6) cout << "YES" << endl;
            else                   cout << "NO"  << endl;
        }
    }
    return 0;
}

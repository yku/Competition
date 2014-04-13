#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;
typedef long long ll;

int main()
{
    int T;

    cin >> T;
    for(int i = 1; i <= T; i++) {
        double C, F, X;
        double ans = 1000000.0;
        cin >> C >> F >> X;
       
        for(int n = 0; true; n++) {
            double t = 0.0;
            for(int k = 0; k < n; k++) {
                t += C / (2+k*F);    
            }
            t += X / (2+n*F);
            if(ans > t) ans = t;
            else break;
        }
        cout << "Case #" << i << ": " << fixed << setprecision(7) << ans << endl; 
    }

    return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int solve(ll e)
{
    ll x, y, z;
    ll ret = 1 << 30;
    for(z = 0; z * z * z <= e; z++) {
        for(y = 0; y * y <= e; y++) {
            x = e - (y*y + z*z*z);
            if(x >= 0)  
                ret = min(ret, x+y+z);
        }
    }
    return ret;
}

int main()
{
    ll e;

    while(true) {
        cin >> e;
        if(e == 0) break;

        cout << solve(e) << endl;
    }

    return 0;
}

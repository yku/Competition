#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int solve(ll N) 
{
    int ret = 0;
    bool carry = false;
    
    while(N) {
        int x;
        if(carry) {
            if(N & 1) { x = 2; carry = true; }
            else      { x = 1; carry = true; }
        } else {
            if(N & 1) { x = 1; carry = false; }
            else      { x = 2; carry = true; }
        }
        ret += x; 
        N >>= 1;
    }
    if(carry) ret -= 2;

    return ret;
}

int main()
{
    int T;

    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        ll N;
        scanf("%lld", &N);
        cout << "Case #" << i << ": " << solve(N) << endl;

    }

}

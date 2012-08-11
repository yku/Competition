#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;
typedef long long ll;

bool isPrime(ll n)
{
    if(n == 1 || n % 2 == 0) return false;
    for(ll i = 3; i*i <= n; i += 2) 
        if(n % i == 0) return false;
    return true;
}

int main()
{
    string s = "";
    ll ans = 0;
    for(int i = 1; i <= 9; i++) {
        stringstream t;
        t << i;
        s += t.str();
        sort(s.begin(), s.end());
        do {
            stringstream ss(s);
            ll n;
            ss >> n;
            if(isPrime(n)) 
                ans = max(ans, n);
        }while(next_permutation(s.begin(), s.end()));
    }
    cout << ans << endl;
    return 0;
}

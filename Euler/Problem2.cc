#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
int main()
{
    ll a = 0, a1 = 1, a2 = 1;
    ll sum = 0;

    while(true) {
        a = a1 + a2;
        a1 = a2;
        a2 = a;
        if(a >= 4000000) break;
        if(a%2==0) sum += a;
    }
    cout << sum << endl;
    return 0;
}


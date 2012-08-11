#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;
typedef long long ll;
const int n = 1000000;
bool primes[n+1];

void init(void)
{
    fill(primes, primes+(n+1), true);
    primes[0] = primes[1] = false;
    for(int i = 2; i <= n; i++) {
        if(primes[i]) {
            for(int j = 2; i * j <= n; j++)
                primes[i*j] = false;
        }
    }
}

bool isOddComposite(int x)
{
    for(int i = x; i > 0; i--) {
        double t = (double)x;
        if(primes[i]) {
            t -= (double)i;
            t /= 2.0; 
            t = sqrt(t);
            if(t == (int)t) return true;
        }
    }
    return false;
}

int main()
{
    init();
    
    for(int i = 9; i <= n; i += 2) {
        if(primes[i]) continue;
        if(!isOddComposite(i)) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}


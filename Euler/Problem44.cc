#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;
typedef long long ll;
int memo[10001];

/**
 * Pn = n * (3*n - 1) / 2 をnについて解の公式で解いた
 */
bool isPentagonal(int x)
{
    double n = (1.0 + sqrt(1+24*x)) / 6.0;
    if(n == (int)n)
        return true;
    return false;
}

int getPentagonal(int n)
{
    if(memo[n] != -1) return memo[n];
    memo[n] = (n * (3*n - 1) / 2);
    return memo[n];
}

int main()
{
    memset(memo, -1, sizeof(memo));
    bool not_found = true; 
    int i = 1;
    while(not_found and i <= 10000) {
        i++;
        for(int j = i - 1; j > 0; j--) {
            int x = getPentagonal(i) + getPentagonal(j);
            int d = getPentagonal(i) - getPentagonal(j);
            if(isPentagonal(x) and isPentagonal(d)) {
                cout << d << endl;
                not_found = false;
                break;
            }
        }
    }
    
    return 0;
}

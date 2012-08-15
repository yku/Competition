#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;
typedef long long ll;

#define MAX_N 1000001
#define IS_PRIME(X) d[X]
vector<int> primes;
bool d[MAX_N];

void init(void)
{
    fill(d, d+sizeof(d), true);
    d[0] = d[1] = false;
    for(int i = 2; i*i < MAX_N; i++) {
        if(d[i]) {
            for(int j = 2; i*j < MAX_N; j++) 
                d[i*j] = false;
        }
    }
    for(int i = 0; i < MAX_N; i++)
        if(d[i]) primes.push_back(i);

}
/**
 * 素数nを与えて、nに一致するか超えるかまでを小さい素数の和で求めていく
 * => 答えはでるが遅すぎる.
 */
int solve(int n)
{
    int t = 0, c = 0, b = 0;
    for(int i = 0; i < primes.size() and primes[i] <= n; i++) {
        t += primes[i];
        c++;
        while(n < t) {
            t -= primes[b++];
            c--;
        }
        if(t == n) return c;
    }
    return 0;
}

int main()
{
    init();
    
    int ans = 0;
    int max_t = 0;
   
    // 小さい素数から足していき、できた数字が素数かどうかで判定する
    for(int i = 0; i < primes.size(); i++) {
        int t = 1;
        int n = primes[i];
        for(int j = i+1; j < primes.size(); j++) {
            n += primes[j];
            t++;
            if(n >= MAX_N) break;
            if(IS_PRIME(n) and max_t < t){
                max_t = t;
                ans = n;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

bool primes[1000001];

void init_prime(void)
{
    for(int i = 0; i < 1000000; i++) primes[i] = true;

    primes[0] = primes[1] = false; 
    for(int i = 2; i <= 1000000; i++) {
        if(primes[i]) {
            for(int j = 2; i*j <= 1000000; j++)
                primes[i*j] = false;
        }
    }
}

// dp[i][j] := i番目までの料理から支払う金額がjとなるように選べるかどうか(boolean)
// dp[j] := dp[i][j]の簡略化表現 
int solve(int budget, vector<int>& v)
{
    int ret = 0;
    bool dp[budget+1];
 
    for(int i = 0; i < budget+1; i++) dp[i] = false;

    dp[0] = true;
    for(int i = 0; i < v.size(); i++) {
        for(int j = v[i]; j <= budget; j++) {
            // dp[j] = max(dp[j], dp[j-v[i]]+v[i])のboolean version
            dp[j] |= dp[j-v[i]];
        }
    }

    for(int j = budget; j >= 0; j--) {
        if(dp[j] and primes[j]) {
            ret = j;
            break;
        }
    }

    return ret;
}


int main()
{
    int n, budget;

    init_prime();
    while(true) {
        cin >> n >> budget;
        if(n == 0 and budget == 0) break;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int price;
            cin >> price;
            v.push_back(price);
        }
        int ret = solve(budget, v);
        if(ret) cout << ret << endl;
        else    cout << "NA" << endl;
    }

    return 0;
}

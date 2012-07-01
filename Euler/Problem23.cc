#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int sum = 28123 * 28124 / 2;

int d(int n)
{
    if(n == 1) return 1;
    int ret = 1;
    for(int i = 2; i <= (n/2)+1; i++) {
        if(n % i == 0) { ret += n / i; }
    }
    return ret;
}

bool abundant(int n)
{
    if(n < d(n)) return true;
    else return false;
}

int main()
{
    vector<int> v;
    bool used[28124];

    fill(used, used+sizeof(used), false);
    for(int i = 1; i <= 28123; i++) 
        if(abundant(i)) v.push_back(i); 
    
    for(int i = 0; i < v.size(); i++) {
        for(int j = i; j < v.size(); j++) {
            if(v[i]+v[j] <= 28123 && used[v[i]+v[j]] == false) {
                sum -= (v[i]+v[j]);
                used[v[i]+v[j]] = true;
            }
        }
    }
    cout << sum << endl;
    return 0;
}


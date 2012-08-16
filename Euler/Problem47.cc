#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;
typedef long long ll;

map<int,int> prime_factors(int n)
{
    map<int,int> res;
    for(int i = 2; i*i <= n; i++) {
        while(n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}

int main()
{

    set<int> s;
    int cnt = 0, ans = 0, base = 4;
    for(int i = 1; ; i++) {
        bool distinct = true;

        map<int,int> p = prime_factors(i);
        map<int,int>::iterator it = p.begin();
        while(it != p.end()) {
            int t = pow((*it).first, (*it).second);
            if(p.size() != base or s.count(t)) {
                distinct = false;
                s.clear();
                break;
            }
            s.insert(t); 
            it++;
        }
        if(distinct) cnt++;
        else cnt = 0;
        if(cnt == base) { ans = i - base + 1; break; }
    }
    cout << ans << endl;
    return 0;
}

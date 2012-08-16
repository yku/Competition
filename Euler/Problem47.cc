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
    int cnt = 0, ans = 0;
    for(int i = 2; i <= 1000; i++) {
        bool distinct = true;
        map<int,int> p;
        p = prime_factors(i);
        map<int,int>::iterator it = p.begin();
        while(it != p.end()) {
            int t = pow((*it).first, (*it).second);
            cout << "cnt=" << cnt << " t=" << t << endl;
            if(s.count(t)) {
                distinct = false;
                s.clear();
                break;
            }
            s.insert(t); 
            it++;
        }
        if(distinct) cnt++;
        else cnt = 0;
        if(cnt == 3) { ans = i - 3; break; }
    }
    cout << ans << endl;
    return 0;
}


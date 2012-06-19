#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

bool prime[1000001];

bool init(void)
{
    fill(prime, prime+sizeof(prime), true);
    prime[0] = prime[1] = false;
    for(int i = 2; i <= 1000000; i++) {
        if(prime[i]) {
            for(int j = 2; i*j <= 1000000; j++) prime[i*j] = false;
        }
    }

}

int solve(void)
{
    int ret = 0;
    for(int i = 0; i <= 1000000; i++) {
        if(!prime[i]) continue;
        int n;
        bool circular = true;
        stringstream ss;
        ss << i;
        string s = ss.str();
        string t(s); 
        for(int j = 0; j < s.length(); j++) {
            rotate(s.begin(), s.begin()+j, s.end());
            ss.clear();
            ss.str("");
            ss << s;
            ss >> n;
            s = t;
            if(!prime[n]) { circular = false;  }
        }
        if(circular){
            ret++;
        }
    }

    return ret;
}

int main()
{
    init();
    cout << solve() << endl;
    return 0;
}


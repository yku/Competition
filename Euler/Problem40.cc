#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int d[1000007];

int solve()
{
    long long a = 1, b;
    for(int i = 1; a <= 1000000; i++) {
        //if(a == 1 or a == 10 or a == 100 or a == 1000 or a == 10000 or a == 100000 or a == 1000000)
            // a が n th
        //    cout << i << ":" << a << "th" << endl;
        //if(a == 9998)  
        //    cout << i << ":" << a << "th" << endl;
        int digits = 0;
        long long t = i;
        vector<int> v;
        while(t) {
            digits++;
            v.push_back(t%10);
            t /= 10;
        }
        reverse(v.begin(), v.end());
    
        for(int j = 0; j < digits; j++)
            d[a+j] = v[j];

        b = a + digits;
        a = b;
    }
    //cout << d[1] << "," << d[100] << "," << d[1000] << "," << d[10000] << "," << d[100000] << "," << d[1000000] << endl;
    return d[1]*d[100]*d[1000]*d[10000]*d[100000]*d[1000000];
}


int main()
{
    cout << solve() << endl;
    return 0;
}


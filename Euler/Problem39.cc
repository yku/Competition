#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solve(int p)
{
    int ans = 0;
    
    for(int a = 1; a < p; a++) {
        for(int b = a+1; b < p - (a+b); b++) {
            if(a*a+b*b == (p-(a+b)) * (p - (a+b))) ans++;
        }
    }
    
    return ans;
}

int main()
{
    int ans;
    int t_max = 0;
    for(int i = 1; i <= 1000; i++) {
        int t = solve(i);
        if(t_max < t) {
            t_max = t;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int solve(int n)
{
    int ret = 100000;

    while(n--) {
        ret = ret * 1.05;
        if(ret % 1000)
            ret = ret - ret % 1000 + 1000;
    }
    return ret;
}

// solve2だと通らん...
int solve2(int n)
{
    double ret = 100.0;

    while(n--) {
        ret = ceil(ret*1.05);
    }
    return (int)ret;
}

int main()
{
    int n;
    while(cin >> n) {
        cout << solve(n) << endl;
        //cout << solve2(n) << "000" <<  endl;
    }
    return 0;
}

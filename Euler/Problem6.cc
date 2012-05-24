#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

/**
 * 1. a^2 + b^2 
 * 2. (a+b)^2 = a^2 + 2ab + b^2
 *
 * => 2. - 1. = 2ab
 *
 * 一般化すると
 * 2(ab + ac + ad + ... + bc + bd + ...)
 * 1,2,3,...,100なので
 * ab -> 1*2 ac -> 1*3 ad -> 1*4 ...
 *           bc -> 2*3 bd -> 2*4 ...
 *                     cd -> 3*4
 */
int solve(int n)
{
    int ret = 0;
    for(int i = 1; i < n; i++)
        for(int j = i+1; j <= n; j++)
            ret += i*j;
    return 2*ret;
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}


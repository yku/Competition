#include <iostream>

using namespace std;

int f(int x) { return x*x; }

int solve(int d)
{
    int ret = 0;
   
    for(int n = 1; n*d < 600; n++)
        ret += f(n*d) * d;

    return ret;
}

int main()
{
    int d;
    while(cin >> d) cout << solve(d) << endl;
    return 0;
}

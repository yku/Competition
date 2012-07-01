#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int d(int n)
{
    if(n == 1) return 1;
    int ret = 1;
    for(int i = 2; i <= (n/2)+1; i++) {
        if(n % i == 0) { ret += n / i; }
    }
    return ret;
}

bool amicable(int a)
{
    int b = d(a);
    if(d(b) == a && a != b) return true;
    else return false;
}

int main()
{
    int ans = 0;
    for(int i = 0; i <= 10000; i++)
        if(amicable(i)) ans += i;
    cout << ans << endl;
    return 0;
}

#include <iostream>

using namespace std;

int solve(int a, int b)
{
    int ret = 0;
    int n = a + b;

    while(n) {
        n /= 10;
        ret++;
    }
    return ret;
}

int main()
{
    int a, b;

    while(cin >> a >> b) {
        cout << solve(a, b) << endl;
    }

    return 0;
}

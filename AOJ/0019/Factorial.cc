#include <iostream>

using namespace std;
typedef long long ll;

ll solve(int n)
{
    if(n == 0) return 1;
    else       return n * solve(n-1);
}

int main()
{
    int n;
    while(cin >> n) {
        cout << solve(n) << endl;
    }
    return 0;
}

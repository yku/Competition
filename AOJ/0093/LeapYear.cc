#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool isLeapYear(int year)
{
    if(year % 4 == 0) {
        if(year % 400 == 0) return true;
        if(year % 100 == 0) return false;
        return true;
    }
    return false;
}

void solve(int a, int b)
{
    bool na = true;

    for(int i = a; i <= b; i++) {
        if(isLeapYear(i)) { cout << i << endl; na = false; }
    }
    if(na) cout << "NA" << endl;
}

int main()
{
    int a, b;
    bool f = false;
    while(cin >> a >> b) {
        if(!(a || b)) break;
        if(f) cout << endl;
        solve(a, b);
        f = true;
    }
    return 0;
}


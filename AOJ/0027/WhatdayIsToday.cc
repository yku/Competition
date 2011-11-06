#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
const string days[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

string solve(int m, int q)
{
    int J = 20;
    int K = 4;
    if(m == 1 or m == 2) { K = 3; m += 12; } 
    // ツェラーの公式
    // http://ja.wikipedia.org/wiki/%E3%83%84%E3%82%A7%E3%83%A9%E3%83%BC%E3%81%AE%E5%85%AC%E5%BC%8F
    int h = (q + (int)floor(((m+1)*26)/10) + K + (int)floor(K/4) + (int)floor(J/4) + 5*J) % 7;
    return days[h];
}

int main()
{
    int m, q;
    while(cin >> m >> q, m or q) {
        cout << solve(m, q) << endl;
    }
    return 0;
}


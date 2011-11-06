#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solve(string s)
{
    stringstream ss;
    int max, min;
    
    sort(s.begin(), s.end());
    ss << s;
    ss >> min;

    ss.str("");
    ss.clear();
    
    reverse(s.begin(), s.end());
    ss << s;
    ss >> max;

    return (max - min);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}

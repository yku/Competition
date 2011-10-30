#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    string s;
    while(cin >> s) {
        reverse(s.begin(), s.end());
        cout << s << endl;
    }

    return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solve(int n)
{
    int ret = 0;

    // 10^4 なので十分間に合う
    for(int a = 0; a <= 9; a++) 
        for(int b = 0; b <= 9; b++) 
            for(int c = 0; c <= 9; c++) 
                for(int d = 0; d <= 9; d++) 
                    if((a+b+c+d) == n) ret++;
    
    return ret;
}

int main()
{
    int n;

    while(cin >> n) {
        cout << solve(n) << endl;
    }

    return 0;
}


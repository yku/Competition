#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int coins[4] = { 10, 50, 100, 500 };
void solve(int bill, int k[])
{
    int sum = 0;
    int r[4]; // おつりの枚数

    memset(r, 0, sizeof(r));
    for(int i = 0; i < 4; i++)
        sum += coins[i] * k[i];
    
    int change = sum - bill;
    for(int i = 3; i >= 0; i--) {
        while(change >= coins[i]) {
            change -= coins[i];
            r[i]++;
        }
    }
    for(int i = 0; i < 4; i++) {
        int x = k[i] - r[i];
        if(x > 0) { // 表示用(なくても本質的には関係ない)
            cout << coins[i] << " "  << x << endl;
        }
    }

}

int main()
{
    while(true) {
        int bill;
        int k[4];

        cin >> bill;
        if(bill == 0) break;
        for(int i = 0; i < 4; i++) {
            cin >> k[i];
        }
        solve(bill, k);
    }

    return 0;
}


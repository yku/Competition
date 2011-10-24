#include <iostream>
#include <vector>

using namespace std;

const int coins[4] = { 10, 50, 100, 500 };
void solve(int bill, int k[])
{
    int ans[4];
    int minans = 60000;
    for(int a = 0; a <= k[0]; a++) {
        for(int b = 0; b<= k[1]; b++) {
            for(int c = 0; c<= k[2]; c++) {
                for(int d = 0; d <= k[3]; d++) {
                    int sum = a * coins[0] + b * coins[1] + c * coins[2] + d * coins[3];
                    if(sum < bill) continue;
                    int change = sum - bill;
                    int tc[4];
                    tc[0] = k[0] - a;
                    tc[1] = k[1] - b;
                    tc[2] = k[2] - c;
                    tc[3] = k[3] - d;
                    for(int i = 3; i >= 0; i--) {
                        while(change >= coins[i]) {
                            change -= coins[i];
                            tc[i]++;
                        }
                    }
                    int t = 0;
                    for(int i = 0; i < 4; i++) t += tc[i];
                    if(t < minans) {
                        ans[0] = a;
                        ans[1] = b;
                        ans[2] = c;
                        ans[3] = d;
                        minans = t;
                    }
                }
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        if(ans[i] != 0)
            cout << coins[i] << " " << ans[i] << endl;
    }
    cout << endl;

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


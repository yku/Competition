#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <sstream>

using namespace std;
typedef long long ll;

int main()
{
    int T;
    cin >> T;
    int fst, snd;

    for(int cases=1; cases <= T; cases++) {
        int arr[16+1] = {0};   
        cin >> fst;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int t;
                cin >> t;
                if(i+1 == fst) {
                    arr[t]++;
                }
            }
        }

        cin >> snd;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int t;
                cin >> t;
                if(i+1 == snd) {
                    arr[t]++;
                }
            }
        }

        int f = 0;
        int ans;
        for(int i = 0; i <= 16; i++) {
            if(arr[i] == 2){ f++; ans = i; }
        }

        cout << "Case #" << cases << ": ";
        if(f >= 2) {
            cout << "Bad magician!" << endl;
        }
        else if(f == 1) {
            cout << ans << endl;
        }
        else {
            cout << "Volunteer cheated!" << endl;
        }
    }
    return 0;
}


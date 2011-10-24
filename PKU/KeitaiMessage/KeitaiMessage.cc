#include <iostream>
#include <vector>

using namespace std;

const char dict[][5] = {
    {'-', '-', '-', '-', '-'}, // 0
    {'.', ',', '!', '?', ' '}, // 1
    {'a', 'b', 'c', '-', '-'}, // 2
    {'d', 'e', 'f', '-', '-'}, // 3
    {'g', 'h', 'i', '-', '-'}, // 4
    {'j', 'k', 'l', '-', '-'}, // 5
    {'m', 'n', 'o', '-', '-'}, // 6
    {'p', 'q', 'r', 's', '-'}, // 7
    {'t', 'u', 'v', '-', '-'}, // 8
    {'w', 'x', 'y', 'z', '-'}, // 9
};

void solve(string s)
{
    int count = -1;
    for(int i = 0; i < s.length(); i++) {
        int n = s[i] - '0';
        if(n == 0) {
            if(count == -1) continue;
            else {
                int x = s[i-1] - '0';
                switch(x) {
                    case 1:
                        cout << dict[x][count % 5];
                        break;
                    case 7:
                    case 9:
                        cout << dict[x][count % 4];
                        break;
                    default:
                        cout << dict[x][count % 3];
                        break;
                }
                count = -1;
            }
        }else{
            count++;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        string s;
        cin >> s;
        solve(s);
        cout << endl;
    }

    return 0;
}

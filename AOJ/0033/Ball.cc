#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int c;
    cin >> c;
    while(c--) {
        int n;
        int A = 0, B = 0;
        bool f = true;
        for(int i = 0; i < 10; i++) {
            cin >> n;
            if(n > A && n > B) {
                if(A > B) A = n;
                else      B = n;
            }
            else if(n > A) {
                A = n;
            }
            else if(n > B) {
                B = n;
            }
            else {
                f = false;
            }
        }
        if(f) cout << "YES" << endl;
        else  cout << "NO" << endl;
    }

    return 0;
}


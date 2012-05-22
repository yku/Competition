#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int numbers[21] = {0};

void factor(int n)
{
    int t[21] = {0};
    for(int i = 2; i <= n; i++) {
        while(n%i == 0) {
            n /= i;
            t[i]++;
        }
        if(!n) break;
    }
    for(int i = 0; i < 21; i++) {
        if(t[i] != 0) {
            numbers[i] = max(numbers[i], t[i]);
        }
    }

}

int main()
{
    int ans = 1;
    for(int i = 1; i <= 20; i++)
        factor(i);
    for(int i = 0; i < 21; i++) {
        if(numbers[i]) { 
            //cout << i << ": " << numbers[i] << endl;
            for(int j = 0; j < numbers[i]; j++)
                ans = ans * i; 
        }
    }
    cout << ans << endl;
    return 0;
}

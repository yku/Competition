#include <iostream>
#include <vector>
using namespace std;
 
static const int MAX_PRIME_NUMBER = 1000000;
 
int solve(vector<int>& primes, long long A, long long B, int P) {
    int result = B - A + 1;
    vector<bool> grouped(B - A + 1, false);
    for (int i = 0; i < primes.size(); i++) {
        int divisor = primes[i];
        if (divisor >= P && divisor < B - A + 1) {
            int remNum = 0;
            int addNum = 0;
            bool isInOtherGroup = false;
            int first = (A % divisor == 0 ? 0 : (divisor - A % divisor));
            for (int j = first; j < grouped.size(); j += divisor) {
                if (!grouped[j]) {
                    remNum++;
                    grouped[j] = true;
                } else {
                    isInOtherGroup = true;
                }
            }
            if (!isInOtherGroup) {
                addNum = 1;
            }
            result -= remNum - addNum;
        }
    }
    return result;
}
 
int main() {
    // prepare prime numbers
    vector<int> primes;
    vector<bool> temp(MAX_PRIME_NUMBER + 1, true);
    for (int i = 2; i <= MAX_PRIME_NUMBER; i++) {
        if (temp[i]) {
            primes.push_back(i);
            for (int j = i; j <= MAX_PRIME_NUMBER; j += i) {
                temp[j] = false;
            }
        }
    }
 
    // read cases from standard input and print result to standard out
    int N, P;
    long long A, B;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B >> P;
        int result = solve(primes, A, B, P);
        cout << "Case #" << i << ": " << result << endl;
    }
 
    return 0;
}


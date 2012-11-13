// 2004 TCCC Online Round 4 Div1 Level1
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;
typedef long long ll;


class BadNeighbors {
public:
int maxDonations(vector<int> donations) {
    int N = donations.size();
    int *dp = new int[N];
    int ret = 0;

    for(int i = 0; i < N -1; i++) {
        if(i == 0 or i == 1) dp[i] = donations[i];
        else {
            dp[i] = max(donations[i] + dp[i-2], dp[i-1]);
        }
    }
    ret = dp[N-2];

    memset(dp, 0, sizeof(int) * N);
    for(int i = 1; i < N; i++) {
        if(i == 1) dp[i] = donations[i];
        else {
            dp[i] = max(donations[i] + dp[i-2], dp[i-1]);
        }
    }
    ret = max(ret, dp[N-1]);

    delete [] dp;
    return ret;
}


void run_test(int Case) {
    test0(); 
    test1(); 
    test2(); 
    test3(); 
    test4(); 
}

private:
void test0() {
    int arr0[] = {10, 3, 2, 5, 7, 8};
    vector<int> arg0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
    int ret;
    int expected = 19; 
    ret = maxDonations(arg0); 
    if(ret == expected) cout << "PASSED" << endl;
    else cout << "Expected:" << expected << " Received:" << ret << endl;
}
void test1() {
    int arr0[] = {11, 15};
    vector<int> arg0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
    int ret;
    int expected = 15; 
    ret = maxDonations(arg0); 
    if(ret == expected) cout << "PASSED" << endl;
    else cout << "Expected:" << expected << " Received:" << ret << endl;
}
void test2() {
    int arr0[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    vector<int> arg0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
    int ret;
    int expected = 16; 
    ret = maxDonations(arg0); 
    if(ret == expected) cout << "PASSED" << endl;
    else cout << "Expected:" << expected << " Received:" << ret << endl;
}
void test3() {
    int arr0[] = {7, 7, 7, 7, 7, 7, 7};
    vector<int> arg0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
    int ret;
    int expected = 21; 
    ret = maxDonations(arg0); 
    if(ret == expected) cout << "PASSED" << endl;
    else cout << "Expected:" << expected << " Received:" << ret << endl;
}
void test4() {
    int arr0[] = {94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
                  6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
                  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72};
    vector<int> arg0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
    int ret;
    int expected = 2926; 
    ret = maxDonations(arg0); 
    if(ret == expected) cout << "PASSED" << endl;
    else cout << "Expected:" << expected << " Received:" << ret << endl;
}
};

int main()
{
    BadNeighbors __test;
    __test.run_test(-1);
}


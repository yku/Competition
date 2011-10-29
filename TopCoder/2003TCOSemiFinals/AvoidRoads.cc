#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class AvoidRoads {
public:
   long numWays(int w, int h, vector<string> bad) {
        int i, j;
        long dp[h+1][w+1];
        bool deadend;

        memset(dp, 0, sizeof(dp));
        
        for(i = 0; i < bad.size(); i++) {
            string s = bad[i];
            int w0 = s[0] - '0';
            int h0 = s[2] - '0';
            int w1 = s[4] - '0';
            int h1 = s[6] - '0';
            dp[h0][w0] = -1;
            dp[h1][w1] = -1;
        }
        dp[0][0] = 0;
        dp[h][w] = 0;

        deadend = false; 
        for(i = 1; i <= w; i++) {
            if(dp[0][i] == -1) deadend = true;
            if(deadend) dp[0][i] = -1;
            else        dp[0][i] = 1;
        }
 
        deadend = false; 
        for(i = 1; i <= h; i++) {
            if(dp[i][0] == -1) deadend = true;
            if(deadend) dp[i][0] = -1;
            else        dp[i][0] = 1;
        }

        for(i = 1; i <= h; i++) {
            for(j = 1; j <= w; j++){
                if(dp[i][j] == -1) continue;
                dp[i][j] = (dp[i-1][j]>0?dp[i-1][j]:0) + (dp[i][j-1]>0?dp[i][j-1]:0);
            }
        }
        return dp[h][w];
    }

   void run_test1(void) {
        long res;
        vector<string> v;
        v.push_back("0 0 0 1");
        v.push_back("6 6 5 6");
        res = numWays(6, 6, v);
        if(res == 252) { cout << "Case0:PASSED" << endl; }
        else { 
            cout << "Case0:FAILED" << endl;
            cout << "Expect:252" << endl; 
            cout << "Result:" << res << endl;
        }
    }

   void run_test2(void) {
        long res;
        vector<string> v;
        v.push_back("");
        res = numWays(1, 1, v);
        if(res == 2) { cout << "Case0:PASSED" << endl; }
        else { 
            cout << "Case1:FAILED" << endl;
            cout << "Expect:2" << endl; 
            cout << "Result:" << res << endl;
        }
    }

   void run_test3(void) {
        long res;
        vector<string> v;
        v.push_back("");
        res = numWays(35, 31, v);
        if(res == 6406484391866534976) { cout << "Case2:PASSED" << endl; }
        else { 
            cout << "Case2:FAILED" << endl;
            cout << "Expect:6406484391866534976" << endl; 
            cout << "Result:" << res << endl;
        }
    }

   void run_test4(void) {
        long res;
        vector<string> v;
        v.push_back("0 0 1 0");
        v.push_back("1 2 2 2");
        v.push_back("1 1 2 1");
        res = numWays(2, 2, v);
        if(res == 0) { cout << "Case3:PASSED" << endl; }
        else { 
            cout << "Case3:FAILED" << endl;
            cout << "Expect:0" << endl; 
            cout << "Result:" << res << endl;
        }
    }
};

int main()
{
    AvoidRoads a;
    a.run_test1();
    a.run_test2();
    a.run_test3();
    a.run_test4();
}

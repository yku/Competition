#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class LuckyCounter {
    public:
        int countLuckyMoments(vector <string> moments) {
            int lucky = 0;
            
            for(int i = 0; i < moments.size(); i++){
                string l, r, rr;
                vector<string> vs = split(moments[i], ":");
                l = vs[0];
                r = vs[1];
                rr = vs[1];
                reverse(rr.begin(), rr.end());
                cout << l << " " <<  r << endl;
                if (l == r || (l[0] == l[1]) && (r[0] == r[1]) || l == rr) {
                    lucky++;
                }
            }

            return lucky;
        }

        vector<string> split(string s, string c)
        {
            vector<string> ret;
            for(int i = 0, n; i <= s.length(); i = n + 1) {
                n = s.find_first_of(c, i);
                if (n == string::npos) n = s.length();
                string tmp = s.substr(i, n - i);
                ret.push_back(tmp);
            }
            return ret;
        }
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

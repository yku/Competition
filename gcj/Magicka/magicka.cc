#include <iostream>
#include <vector>

using namespace std;

string magicka(vector<string> c, vector<string> o, string s) {
    vector<char> v;
    //cout << s << endl;
    for(int i = 0; i < s.length(); i++) {
        v.push_back(s[i]);
        bool removed = false;
        if(v.size() >= 2) {
            char c1 = v[v.size() - 2];
            char c2 = v[v.size() - 1];
            for(int ci = 0; ci < c.size(); ci++) {   
                if(c1 == c[ci][0] && c2 == c[ci][1] || c1 == c[ci][1] && c2 == c[ci][0]) {
                    v.pop_back();
                    v.pop_back();
                    v.push_back(c[ci][2]);
                    removed = true;
                    break;
                }
            }
            if(!removed) {
done:
                for(int j = 0; j < v.size(); j++) {
                    for(int k = j + 1; k < v.size(); k++) {
                        for(int oi = 0; oi < o.size(); oi++) {
                            if(v[j] == o[oi][0] && v[k] == o[oi][1] || v[j] == o[oi][1] && v[k] == o[oi][0]) {
                                v.clear();
                                goto done;
                            }
                        }
                    }
                }
            } 
        }
    }
    /*
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << endl;
    cout << endl;
    */
    string ret = "[";
    for(int i = 0; i < v.size(); i++) {
        ret += v[i];
        if(i != v.size() - 1) ret += ", ";
    }
    ret += "]";
    return ret;
}


int main() {
    int cases;

    scanf("%d", &cases);

    for(int i = 1; i <= cases; i++) {
        // combine
        int c;
        vector<string> combine;
        scanf("%d", &c);
        for(int a = 0; a < c; a++) {
            char sbuf[1000];
            scanf("%s", sbuf);
            combine.push_back(sbuf);
        }
        // opposed
        int o;
        vector<string> opposed;
        scanf("%d", &o);
        for(int a = 0; a < o; a++) {
            char sbuf[1000];
            scanf("%s", sbuf);
            opposed.push_back(sbuf);
        }
        // string
        int n;
        string s;
        scanf("%d", &n);
        {
            char sbuf[1000];
            scanf("%s", sbuf);
            s = sbuf;
        }
        string ret = magicka(combine, opposed, s);
        cout << "Case #" << i << ": " << ret << endl;
    }

    return 0;
}

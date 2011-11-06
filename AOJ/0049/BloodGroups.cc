#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

void solve(vector<string>& v)
{
    map<string, int> blood_grp;
   
    for(int i = 0; i < v.size(); i++) 
        blood_grp[v[i]]++;

    cout << blood_grp["A"] << endl;
    cout << blood_grp["B"] << endl;
    cout << blood_grp["AB"] << endl;
    cout << blood_grp["O"] << endl;
}

int main()
{
    int id;
    char c;
    string blood;
    vector<string> v;
    while(cin >> id >> c >> blood) {
        v.push_back(blood);
    }
    solve(v);

    return 0;
}


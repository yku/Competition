#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

char solve(vector<pair<char, char> >& v)
{
    bool cups[3];

    fill(cups, cups+3, false);
    cups[0] = true;

    for(int i = 0; i < v.size(); i++) {
        int one = v[i].first-'A', two = v[i].second-'A';
        swap(cups[one], cups[two]);
    }
    for(int i = 0; i < 3; i++)
        if(cups[i]) return 'A'+i;
}

int main()
{
    char one, two, c;
    vector<pair<char, char> > v;
    while(cin >> one >> c >> two) {
        v.push_back(pair<char, char>(one, two));
    }
    cout << solve(v) << endl;
    
    return 0;
}

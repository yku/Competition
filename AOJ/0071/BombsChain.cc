#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void dump(vector<string>& v)
{
    for(int i = 0; i < v.size(); i++) 
        cout << v[i] << endl;
}

vector<string> solve(vector<string> v, int x, int y) 
{
    vector<string> ret(v);
    int w = v[0].size(), h = v.size();
    queue<pair<int,int> > q;
    
    q.push(pair<int, int>(x-1, y-1));

    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int tx = p.first, ty = p.second;
        ret[ty][tx] = '0'; 
        for(int dy = -3; dy <= 3; dy++) {
            for(int dx = -3; dx <= 3; dx++) {
                int nx = tx+dx, ny = ty+dy;
                if(nx < 0 || nx >= w || ny < 0 || ny >= h || (dx && dy) || (dx == 0 && dy ==0)) continue;
                if(ret[ny][nx] == '1') 
                    q.push(pair<int, int>(nx, ny));
            }
        }
    
    }

    return ret;
}

int main()
{
    int d;
    cin >> d;
    for(int c = 1; c <= d; c++) {
        string s;
        vector<string> v, ret;
        int x, y;
        cin.ignore();
        for(int i = 0; i < 8; i++) {
            cin >> s;
            v.push_back(s);
        }
        cin >> x >> y;
        ret = solve(v, x, y);
        cout << "Data " << c << ":" << endl;
        dump(ret);
    }
    return 0;
}


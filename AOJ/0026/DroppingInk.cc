#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int map[10][10];

void euclidean(int x, int y)
{
    for(int dy = -1; dy <= 1; dy++) {
        for(int dx = -1; dx <= 1; dx++) {
            int xx = x + dx, yy = y + dy;
            if(xx >= 0 and yy >= 0 and xx < 10 and yy < 10)
                map[xx][yy]++;
        }
    }
}

void manhattan(int x, int y, int n)
{
    for(int dy = -n; dy <= n; dy++) {
        for(int dx = -n; dx <= n; dx++) {
            int xx = x + dx, yy = y + dy;
            if(xx < 0 or xx >= 10 or yy < 0 or yy >= 10) continue; 
            int distance = abs(x - xx) + abs(y - yy);
            if(distance <= n) map[xx][yy]++;
        }
    }
}

void solve(vector<int>& vx, vector<int>& vy, vector<int>& vsize)
{
    int spaces = 0, deep = 0;
    memset(map, 0, sizeof(map));
    for(int i = 0; i < vsize.size(); i++) {
        switch(vsize[i]) {
            case 1:
                manhattan(vx[i], vy[i], 1);
                break;
            case 2:
                euclidean(vx[i], vy[i]);
                break;
            case 3:
                manhattan(vx[i], vy[i], 2);
                break;
        }
    }

    for(int y = 0; y < 10; y++) {
        for(int x = 0; x < 10; x++) {
            //cout << map[x][y] << " ";
            if(map[x][y])
                deep = max(map[x][y], deep);
            else
                spaces++;
        }
        //cout << endl;
    }
    cout << spaces << endl;
    cout << deep << endl;
}

int main()
{
    int x, y, size;
    char c;
    vector<int> vx, vy, vsize;
    while(cin >> x >> c >> y >> c >> size) {
        vx.push_back(x);
        vy.push_back(y);
        vsize.push_back(size);
    }
    solve(vx, vy, vsize);

    return 0;
}

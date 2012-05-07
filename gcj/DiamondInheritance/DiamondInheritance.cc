#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef vector< vector<int> > VV;

void dump(VV parent)
{
    int N = parent.size() - 1;
    for(int i = 1; i <= N; i++) {
        cout << "Class" << i << ": ";
        for(int j = 1; j <= N; j++) {
            cout << parent[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> getParents(int c, VV& v)
{
    int N = v.size() - 1;
    vector<int> ret;
    for(int i = 1; i <= N; i++) {
        if(v[c][i] == 1) ret.push_back(i);
    }
    return ret;
}

bool dfs(int current, VV& v, bool visited[])
{
    if(visited[current]) return true;
    visited[current] = true;
    bool ret; 
    vector<int> parents;
    parents = getParents(current, v);
    if(parents.size() == 0) return false;
    for(int i = 0; i < parents.size(); i++) {
        ret = dfs(parents[i], v, visited);
        if(ret) return true;
    }
    return false;
}

int main()
{
    int T;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        VV parent(N+1, vector<int>(N+1,0));

        for(int j = 1; j <= N; j++) {
            int M;
            cin >> M;
            for(int k = 0; k < M; k++) {
                int c;
                cin >> c;
                parent[j][c] = 1;
            }
        }
        //dump(parent);
        bool ret;
        for(int r = 1; r <= N; r++) {
            bool visited[N+1];
            memset(visited, false, sizeof(visited));
            ret = dfs(r, parent, visited);
            if(ret) break;
        }
        cout << "Case #" << i << ": ";
        if(ret) cout << "Yes" << endl;
        else    cout << "No" << endl;
    }

    return 0;
}


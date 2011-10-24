#include <iostream>
#include <queue>

const int N = 10;
const int M = 10;
const int sx = 1, sy = 0;
const int gx = 8, gy = 9;
const char maze[N][M] = {
    {'#','S','#','#','#','#','#','#','.','#'},
    {'.','.','.','.','.','.','#','.','.','#'},
    {'.','#','.','#','#','.','#','#','.','#'},
    {'.','#','.','.','.','.','.','.','.','.'},
    {'#','#','.','#','#','.','#','#','#','#'},
    {'.','.','.','.','#','.','.','.','.','#'},
    {'.','#','#','#','#','#','#','#','.','#'},
    {'.','.','.','.','#','.','.','.','.','.'},
    {'.','#','#','#','#','.','#','#','#','.'},
    {'.','.','.','.','#','.','.','.','G','#'},
};

const int INF = 1 << 30;
typedef std::pair<int, int> P;

int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

int bfs()
{
    std::queue<P> q;
    int dist[N][M];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) dist[i][j] = INF;

    q.push(P(sx, sy));
    dist[sy][sx] = 0;

    while(q.size()) {
        P p = q.front(); q.pop();
        if(p.first == gx && p.second == gy) break;
        for(int i = 0; i < 4; i++) {
            int xx = p.first + dx[i], yy = p.second + dy[i];

            if(0 <= xx && xx < M && 0 <= yy && yy < N && maze[yy][xx] != '#' && dist[yy][xx] == INF)
            {
                q.push(P(xx, yy));
                dist[yy][xx] = dist[p.second][p.first] + 1;
            }
        }
    }
    return dist[gy][gx];
}

int main()
{
    int ret = bfs();
    std::cout << ret << std::endl;
}

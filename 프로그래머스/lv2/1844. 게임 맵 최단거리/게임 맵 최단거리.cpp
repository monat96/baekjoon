#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};

bool oob(int y, int x, int sizeY, int sizeX)
{
    return (y < 0 || x < 0 || y >= sizeY || x >= sizeX);
}

int dist[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int n = int(maps.size());
    int m = int(maps[0].size());
    
    for(int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);
    queue<pair<int, int>> que;
    
    que.push({0, 0});
    dist[0][0] = 1;
    
    while(!que.empty()) {
        auto curr = que.front();
        que.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int ay = curr.first + dy[dir];
            int ax = curr.second + dx[dir];
            
            if (oob(ay, ax, n, m)) continue;
            if (dist[ay][ax] != -1 || maps[ay][ax] == 0) continue;
            
            que.push({ay, ax});
            dist[ay][ax] = dist[curr.first][curr.second] + 1;
            
        }
    }
    return dist[n-1][m-1];
}
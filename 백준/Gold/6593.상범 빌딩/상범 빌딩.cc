#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define WALL '#'
#define PATH '.'

const int dz[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dx[] = {0, 0, 0, 0, 1, -1};

string graph[31][31];
int visited[31][31][31];

int z, y, x, startZ, startY, startX, endZ, endY, endX;

bool notInRange(int z, int y, int x, int sizeZ, int sizeY, int sizeX)
{
    return (z < 0 || y < 0 || x < 0 || z >= sizeZ || y >= sizeY || x >= sizeX || visited[z][y][x] != -1 || graph[z][y][x] == WALL);
}

int bfs(int z, int y, int x, int sizeZ, int sizeY, int sizeX)
{
    queue<vector<int>> que;
    que.push({z, y, x});
    visited[z][y][x] = 0;

    while (!que.empty())
    {
        int currZ = que.front()[0];
        int currY = que.front()[1];
        int currX = que.front()[2];
        que.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            int az = currZ + dz[dir];
            int ay = currY + dy[dir];
            int ax = currX + dx[dir];

            if (notInRange(az, ay, ax, sizeZ, sizeY, sizeX))
                continue;
            que.push({az, ay, ax});
            visited[az][ay][ax] = visited[currZ][currY][currX] + 1;
            if (az == endZ && ay == endY && ax == endX)
                return visited[endZ][endY][endX];
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true) {
        cin >> z >> y >> x;
        if(z == 0 && y == 0 && x == 0) break;
        
        for (int i = 0; i < z; i++)
            for (int j = 0; j < y; j++)
                cin >> graph[i][j];

        for (int i = 0; i < z; i++)
            for (int j = 0; j < y; j++)
                for (int k = 0; k < x; k++)
                {
                    visited[i][j][k] = -1;
                    if (graph[i][j][k] == 'S')
                    {
                        startZ = i;
                        startY = j;
                        startX = k;
                    }
                    if (graph[i][j][k] == 'E')
                    {
                        endZ = i;
                        endY = j;
                        endX = k;
                    }
                }
        int ans = bfs(startZ, startY, startX, z, y, x);
        if (ans > 0) cout << "Escaped in " << ans << " minute(s).\n";
        else cout << "Trapped!\n";
    }
    return 0;
}

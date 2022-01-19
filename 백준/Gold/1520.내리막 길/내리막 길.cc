#include <iostream>

using namespace std;

int g[501][501];
int d[501][501];

const int dir[][2] = {{1, 0}, {0, -1}, {-1, 0}, {0,1}};

int dfs(int y, int x, int sizeY, int sizeX)
{
    if(y == sizeY-1 && x == sizeX-1)
        return 1;
    if(d[y][x] != -1)
        return d[y][x];
    
    d[y][x] = 0;
    for(int i = 0; i < 4; i++)
    {
        int ay = y + dir[i][0];
        int ax = x + dir[i][1];

        if(ay >= 0 && ax >= 0 && ay < sizeY && ax < sizeX && g[y][x] > g[ay][ax])
            d[y][x] += dfs(ay, ax, sizeY, sizeX);
    }
    return d[y][x];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
            d[i][j] = -1;
        }
    }
    cout << dfs(0, 0, n, m);
    return 0;
}

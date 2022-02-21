#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

#define WALL 1

const int hy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int hx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int my[] = {-1, 1, 0, 0};
const int mx[] = {0, 0, -1, 1};

int grid[201][201];
int visited[31][201][201];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    int n, m;

    cin >> k;
    cin >> m >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    queue<tuple<int, int, int>> que;

    que.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!que.empty())
    {
        int z, y, x;
        tie(z, y, x) = que.front();
        que.pop();

        if (z < k)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int ay = y + hy[dir];
                int ax = x + hx[dir];
                if (ay < 0 || ax < 0 || ay >= n || ax >= m)
                    continue;
                if (grid[ay][ax] == WALL)
                    continue;
                if (visited[z + 1][ay][ax] > 0)
                    continue;

                visited[z + 1][ay][ax] = visited[z][y][x] + 1;
                que.push({z + 1, ay, ax});
            }
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int ay = y + my[dir];
            int ax = x + mx[dir];
            if (ay < 0 || ax < 0 || ay >= n || ax >= m)
                continue;
            if (grid[ay][ax] == WALL)
                continue;
            if (visited[z][ay][ax] > 0)
                continue;

            visited[z][ay][ax] = visited[z][y][x] + 1;
            que.push({z, ay, ax});
        }
    }
    int ans = 0xffffff;
    for (int i = 0; i <= k; i++)
        if (visited[i][n - 1][m - 1])
            ans = min(ans, visited[i][n - 1][m - 1]);
    if(ans == 0xffffff) cout << -1;
    else cout << ans - 1;
    return 0;
}

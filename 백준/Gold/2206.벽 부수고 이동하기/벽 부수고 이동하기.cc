#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

string board[1001];
int dist[2][1001][1001];

int bfs(int n, int m)
{
    queue<tuple<int, int, int>> que;
    dist[0][0][0] = dist[1][0][0] = 1;
    que.push({0, 0, 0});

    while (!que.empty())
    {
        int broken, y, x;
        tie(broken, y, x) = que.front();
        que.pop();
        if (y == n - 1 && x == m - 1)
            return dist[broken][y][x];

        for (int dir = 0; dir < 4; dir++)
        {
            int ay = y + dy[dir];
            int ax = x + dx[dir];
            // 범위을 초과한경우
            if(ay < 0 || ax < 0 || ay >= n || ax >= m) continue;
            // 벽을 부시지 않았고 방문이 가능한경우
            if(board[ay][ax] == '0' && dist[broken][ay][ax] == -1) {
                dist[broken][ay][ax] = dist[broken][y][x] + 1;
                que.push({broken, ay, ax});
            }
            // 아직 벽을 부시지 않음, 벽을 부시고 가야하며 방문을 안한경우
            if(broken == 0 && board[ay][ax] == '1' && dist[1][ay][ax] == -1) {
                dist[1][ay][ax] = dist[broken][y][x] + 1;
                que.push({1, ay, ax});
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        fill(dist[0][i], dist[0][i] + m, -1);
        fill(dist[1][i], dist[1][i] + m, -1);
    }
    for (int i = 0; i < n; i++)
        cin >> board[i];

    cout << bfs(n, m);

    return 0;
}

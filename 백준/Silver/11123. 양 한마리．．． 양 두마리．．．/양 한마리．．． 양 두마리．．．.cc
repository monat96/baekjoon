#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 101;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};

void bfs(vector<string> &maps, int sizeY, int sizeX, int y, int x) {
  queue<pair<int, int>> que;
  que.push({y, x});
  maps[y][x] = '.';

  while (!que.empty()) {
    int currY, currX;
    tie(currY, currX) = que.front();
    que.pop();

    for (int dir = 0; dir < 4; dir++) {
      int ay = currY + dy[dir];
      int ax = currX + dx[dir];

      if (ay < 0 || ax < 0 || ay >= sizeY || ax >= sizeX) continue;
      if (maps[ay][ax] == '.') continue;
      que.push({ay, ax});
      maps[ay][ax] = '.';
    }
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<string> maps(MAX);
    for (int i = 0; i < n; i++) cin >> maps[i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (maps[i][j] == '#') {
          cnt++;
          bfs(maps, n, m, i, j);
        }
      }
    cout << cnt << '\n';
  }
  return 0;
}
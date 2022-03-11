#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 251;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

string maps[MAX];
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));

int wolf = 0, sheep = 0;

void bfs(int y, int x, int sizeY, int sizeX) {
  int w = 0, s = 0;
  queue<pair<int, int>> que;

  que.push({y, x});
  visited[y][x] = true;

  while (!que.empty()) {
    pair<int, int> curr = que.front();
    que.pop();

    if (maps[curr.first][curr.second] == 'v')
      w++;
    else if (maps[curr.first][curr.second] == 'o')
      s++;

    for (int dir = 0; dir < 4; dir++) {
      int ay = curr.first + dy[dir];
      int ax = curr.second + dx[dir];

      if (ay < 0 || ax < 0 || ay >= sizeY || ax >= sizeX) continue;
      if (visited[ay][ax] || maps[ay][ax] == '#') continue;

      que.push({ay, ax});
      visited[ay][ax] = true;
    }
  }

  if (w >= s)
    wolf += w;
  else if (s > w)
    sheep += s;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) cin >> maps[i];

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      if (maps[y][x] != '#' && !visited[y][x]) {
        bfs(y, x, n, m);
      }
    }
  }
  cout << sheep << ' ' << wolf;
  return 0;
}
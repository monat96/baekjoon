#include <bits/stdc++.h>

using namespace std;

int maps[1001][1001];
vector<bool> visited(1001);

void bfs(int v, int sz) {
  queue<int> que;

  que.push(v);
  visited[v] = true;

  while (!que.empty()) {
    int curr = que.front();
    que.pop();

    cout << curr << ' ';
    for (int i = 1; i <= sz; i++) {
      if (maps[curr][i] == 0 || visited[i]) continue;
      que.push(i);
      visited[i] = true;
    }
  }
}

void dfs(int v, int sz) {
  visited[v] = true;
  cout << v << ' ';

  for (int i = 1; i <= sz; i++) {
    if (maps[v][i] == 0 || visited[i]) continue;
    dfs(i, sz);
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, v;
  cin >> n >> m >> v;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    maps[a][b] = 1;
    maps[b][a] = 1;
  }

  fill(visited.begin(), visited.end(), false);
  dfs(v, n);
  cout << '\n';
  fill(visited.begin(), visited.end(), false);
  bfs(v, n);
  cout << '\n';
  return 0;
}

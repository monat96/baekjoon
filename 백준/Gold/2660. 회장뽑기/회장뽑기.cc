#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> maps;
vector<int> dist(51, -1);

void bfs(int startPoint, int sz) {
  vector<int> visited(sz + 1, -1);
  queue<int> que;

  que.push(startPoint);
  visited[startPoint] = 0;
  int mx = 0;
  while (!que.empty()) {
    int curr = que.front();
    que.pop();

    for (auto nxt : maps[curr]) {
      if (visited[nxt] != -1) continue;

      que.push(nxt);
      visited[nxt] = visited[curr] + 1;
      mx = max(mx, visited[nxt]);
    }
  }
  dist[startPoint] = mx;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (true) {
    int a, b;
    cin >> a >> b;
    if (a == -1 && b == -1) break;

    maps[a].push_back(b);
    maps[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) bfs(i, n);

  int mn = *min_element(dist.begin() + 1, dist.begin() + 1 + n);
  int cnt = count(dist.begin() + 1, dist.begin() + 1 + n, mn);

  cout << mn << ' ' << cnt << '\n';

  for (int i = 1; i <= n; i++)
    if (dist[i] == mn) cout << i << ' ';

  return 0;
}

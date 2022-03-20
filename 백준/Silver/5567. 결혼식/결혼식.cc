#include <bits/stdc++.h>

using namespace std;

const int MAX = 501;

vector<int> maps[MAX];
vector<int> dist(MAX, -1);

void bfs() {
  queue<int> que;
  que.push(1);
  dist[1] = 0;

  while (!que.empty()) {
    int curr = que.front();
    que.pop();
    for (auto nxt : maps[curr]) {
      if (dist[nxt] != -1) continue;
      que.push(nxt);
      dist[nxt] = dist[curr] + 1;
    }
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  while (m--) {
    int a, b;
    cin >> a >> b;
    maps[a].push_back(b);
    maps[b].push_back(a);
  }
  bfs();
  int ans = count_if(dist.begin() + 1, dist.begin() + 1 + n,
                     [](int ele) { return ele > 0 && ele <= 2; });
  cout << ans;
  return 0;
}

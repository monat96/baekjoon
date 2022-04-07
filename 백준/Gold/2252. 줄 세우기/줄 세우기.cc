#include <bits/stdc++.h>

using namespace std;

vector<int> maps[32001];
int indeg[32001];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    maps[a].push_back(b);
    indeg[b]++;
  }
  queue<int> que;
  for (int i = 1; i <= n; i++)
    if (indeg[i] == 0) que.push(i);

  while (!que.empty()) {
    int curr = que.front();
    que.pop();

    cout << curr << ' ';
    for (auto nxt : maps[curr]) {
      indeg[nxt]--;
      if (indeg[nxt] == 0) que.push(nxt);
    }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> maps;
vector<int> visited(300'005, 0);

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  int start, end;

  cin >> n >> m;
  cin >> start >> end;

  while (m--) {
    int a, b;
    cin >> a >> b;
    maps[a].push_back(b);
    maps[b].push_back(a);
  }

  queue<int> que;
  que.push(start);

  while (!que.empty()) {
    int curr = que.front();
    que.pop();

    if (curr == end) break;

    for (auto jump : maps[curr]) {
      if (visited[jump] != 0) continue;
      que.push(jump);
      visited[jump] = visited[curr] + 1;
    }

    for (auto jump : {curr - 1, curr + 1}) {
      if (jump <= 0 || jump >= n + 1) continue;
      if (visited[jump] != 0) continue;
      que.push(jump);
      visited[jump] = visited[curr] + 1;
    }
  }
  cout << visited[end];
  return 0;
}

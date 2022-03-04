#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

map<int, vector<pair<int, int>>, less<int>> maps;
int dist[100'001];
int n;

pair<int, int> dfs(int node) {
  fill(dist + 1, dist + 1 + n, -1);
  stack<pair<int, int>> stck;

  pair<int, int> maxNode = {-1, -1};

  dist[node] = 0;
  stck.push({node, 0});

  while (!stck.empty()) {
    pair<int, int> curr = stck.top();
    stck.pop();
    int currNode = curr.first;
    int currCost = curr.second;

    for (pair<int, int> next : maps[currNode]) {
      int nextNode = next.first;
      int nextCost = next.second;

      if (dist[nextNode] != -1) continue;

      dist[nextNode] = currCost + nextCost;
      stck.push({nextNode, dist[nextNode]});

      if (maxNode.second < dist[nextNode]) maxNode = {nextNode, dist[nextNode]};
    }
  }
  return maxNode;
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int node, link, cost;
    cin >> node;
    while (true) {
      cin >> link;
      if (link == -1) break;
      cin >> cost;
      maps[node].push_back({link, cost});
    }
  }

  auto target = dfs(1);
  auto ans = dfs(target.first);
  cout << ans.second;
  return 0;
}
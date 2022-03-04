#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

const int INF = 0xfffff;

map<int, vector<int>> graph;
int dist[100'001];
int n;

pair<int, int> dijkstra(int node) {
  // cost, node
  pair<int, int> maxNode = {-1, -1};
  priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
      que;

  fill(dist + 1, dist + 1 + n, INF);

  dist[node] = 0;
  que.push({dist[node], node});

  while (!que.empty()) {
    auto curr = que.top();
    que.pop();

    int currNode = curr.second;
    int currCost = curr.first;

    for (auto nextNode : graph[currNode]) {
      int nextCost = currCost + 1;

      if (dist[nextNode] <= nextCost) continue;

      dist[nextNode] = nextCost;
      que.push({nextCost, nextNode});

      if (maxNode.first < nextCost) {
        maxNode.first = nextCost;
        maxNode.second = nextNode;
      }
    }
  }
  return maxNode;
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int startPoint = 1;
  pair<int, int> maxNode = dijkstra(startPoint);

  int d = maxNode.second;
  maxNode = dijkstra(d);
  if (maxNode.first % 2 == 0)
    cout << maxNode.first / 2;
  else
    cout << (maxNode.first / 2) + 1;
  return 0;
}
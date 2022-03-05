#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

const int INF = 0xfffffff;

unordered_map<int, vector<pair<int, int>>> maps;
int dist[801];

void dijkstra(int startPoint, int size) {
  fill(dist + 1, dist + 1 + size, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
      pq;
  dist[startPoint] = 0;
  pq.push({0, startPoint});
  while (!pq.empty()) {
    auto curr = pq.top();
    pq.pop();

    int currCost = curr.first;
    int currNode = curr.second;

    for (auto next : maps[currNode]) {
      int nextCost = next.second;
      int nextNode = next.first;

      if (dist[nextNode] < currCost + nextCost) continue;
      dist[nextNode] = currCost + nextCost;
      pq.push({currCost + nextCost, nextNode});
    }
  }
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, node1, node2;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int s, e, c;
    cin >> s >> e >> c;
    maps[s].push_back({e, c});
    maps[e].push_back({s, c});
  }
  cin >> node1 >> node2;

  int ans1 = 0;
  int ans2 = 0;

  dijkstra(1, n);
  ans1 += dist[node1];
  ans2 += dist[node2];

  dijkstra(node1, n);
  ans1 += dist[node2];
  ans2 += dist[node2];

  dijkstra(n, n);
  ans1 += dist[node2];
  ans2 += dist[node1];

  if (min(ans1, ans2) >= INF)
    cout << -1;
  else
    cout << min(ans1, ans2);
  return 0;
}
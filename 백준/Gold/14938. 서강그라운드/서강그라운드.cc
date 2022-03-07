#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

const int INF = 0x7ffffff;
const int MAX = 1e2 + 1;

int n, m, r;
int ans = 0;
int dist[MAX];
int items[MAX];
unordered_map<int, vector<pair<int, int>>> maps;

void dijkstra(int startPoint, int size) {
  fill(dist + 1, dist + 1 + size, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;
  dist[startPoint] = 0;
  pq.push({dist[startPoint], startPoint});

  while(!pq.empty()) {
    auto curr = pq.top();
    int currCost = curr.first;
    int currNode = curr.second;
    pq.pop();

    for(auto next : maps[currNode]) {
      int nextCost = next.first;
      int nextNode = next.second;
      int cost = currCost + nextCost;

      if(dist[nextNode] < cost) continue;

      dist[nextNode] = cost;
      pq.push({cost, nextNode});
    }
  }
  int sum = 0;
  for(int i = 1; i <= size; i++) {
    if(dist[i] > m) continue;
    sum += items[i];
  }
  ans = max(ans, sum);
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  
  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) cin >> items[i];
  for (int i = 0; i < r; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    maps[a].push_back({l, b});
    maps[b].push_back({l, a});
  }

  for(int i = 1; i <= n; i++)
    dijkstra(i, n);
  cout << ans;
  return 0;
}

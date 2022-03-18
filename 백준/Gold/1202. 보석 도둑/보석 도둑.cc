#include <bits/stdc++.h>

using namespace std;

struct compare {
  bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
  }
};

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  multiset<pair<int, int>, compare> ms;
  multiset<int, less<>> arr;

  int n, k;
  cin >> n >> k;

  while (n--) {
    int m, v;
    cin >> m >> v;
    ms.insert({m, v});
  }
  while (k--) {
    int c;
    cin >> c;
    arr.insert(c);
  }
  long long ans = 0;
  for (auto e : ms) {
    int m, v;
    tie(m, v) = e;
    auto it = arr.lower_bound(m);
    if (it == arr.end()) continue;
    ans += v;
    arr.erase(it);
  }
  cout << ans;
  return 0;
}

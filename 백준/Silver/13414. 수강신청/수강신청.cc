#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  unordered_map<string, int> l;
  vector<pair<int, string>> ans;

  for (int i = 0; i < m; i++) {
    string x;
    cin >> x;
    l[x] = i;
  }

  for (auto ret : l) ans.push_back({ret.second, ret.first});

  sort(ans.begin(), ans.end(), less<pair<int, string>>());

  int idx = n >= int(ans.size()) ? int(ans.size()) : n;
  for (int i = 0; i < idx; i++) cout << ans[i].second << '\n';
  return 0;
}

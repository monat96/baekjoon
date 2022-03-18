#include <bits/stdc++.h>

using namespace std;

struct compare {
  bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
  }
};

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  set<pair<int, int>, compare> ms;
  unordered_map<int, int> dict;

  int n, m;
  cin >> n;
  while (n--) {
    int p, l;
    cin >> p >> l;
    ms.insert({p, l});
    dict[p] = l;
  }
  cin >> m;
  while (m--) {
    string cmd;
    cin >> cmd;
    if (cmd == "add") {
      int p, l;
      cin >> p >> l;
      ms.insert({p, l});
      dict[p] = l;
    } else if (cmd == "recommend") {
      int x;
      cin >> x;
      if (x == 1)
        cout << (*prev(ms.end())).first << '\n';
      else
        cout << (*ms.begin()).first << '\n';
    } else {
      int x;
      cin >> x;
      ms.erase(ms.find({x, dict[x]}));
    }
  }
  return 0;
}

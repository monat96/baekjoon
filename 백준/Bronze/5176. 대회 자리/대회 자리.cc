#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--) {
    int p, m;
    cin >> p >> m;
    unordered_set<int> s;
    for (int i = 0; i < p; i++) {
      int x;
      cin >> x;
      s.insert(x);
    }
    cout << p - int(s.size()) << '\n';
  }
  return 0;
}

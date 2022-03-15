#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, bool> record;

  int n;
  cin >> n;

  for (int i = 0; i < 2 * n - 1; i++) {
    string player;
    cin >> player;
    record[player] = !record[player];
  }

  for (auto ret : record) {
    if (ret.second) {
      cout << ret.first;
      break;
    }
  }

  return 0;
}

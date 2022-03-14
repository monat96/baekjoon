#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_set<string> s;
  string input;
  cin >> input;

  for (int i = 0; i < int(input.size()); i++) {
    for (int j = 1; i + j <= int(input.size()); j++) {
      s.insert(input.substr(i, j));
    }
  }
  cout << int(s.size());
  return 0;
}

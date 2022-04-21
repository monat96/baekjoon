#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str;
  cin >> str;
  int ans = count(str.begin(), str.end(), ',') + 1;
  cout << ans;
  return 0;
}
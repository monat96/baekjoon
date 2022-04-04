#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string str;
  cin >> str;

  int cnt = 0;
  for (int i = 0; i < n - 1; i++)
    if (str.substr(i, 2) == "EW") cnt++;
  cout << cnt;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (auto &ret : arr) cin >> ret;
  sort(arr.begin(), arr.end());
  cout << arr[m-1];
  return 0;
}
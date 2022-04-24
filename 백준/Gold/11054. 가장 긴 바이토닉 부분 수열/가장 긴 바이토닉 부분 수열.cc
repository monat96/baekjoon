#include <bits/stdc++.h>

using namespace std;

void func(vector<int> &arr, vector<int> base, int sz) {
  int tmp[sz];
  int idx = 1;
  tmp[0] = base[0];
  arr[0] = 1;
  for (int i = 1; i < sz; i++) {
    if (tmp[idx - 1] < base[i])
      tmp[idx++] = base[i];
    else {
      int ret = lower_bound(tmp, tmp + idx, base[i]) - tmp;
      tmp[ret] = base[i];
    }
    arr[i] = idx;
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n), lower(n), upper(n);
  for (auto &ret : arr) cin >> ret;
  func(lower, arr, n);
  reverse(arr.begin(), arr.end());
  func(upper, arr, n);
  reverse(upper.begin(), upper.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, lower[i] + upper[i]);
  }
  cout << ans - 1;

  return 0;
}
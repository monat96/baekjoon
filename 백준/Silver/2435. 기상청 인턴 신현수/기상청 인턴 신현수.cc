#include <bits/stdc++.h>

using namespace std;

int arr[101];

int getPsum(int start, int end) {
  int ret = arr[end];
  if (start >= 0) ret -= arr[start];
  return ret;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 1; i < n; i++) arr[i] += arr[i - 1];

  int ans = -10000000;
  for (int i = m - 1; i < n; i++) ans = max(ans, getPsum(i - m, i));
  cout << ans;

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> base(n), lower(n), upper(n);
  for (auto &ret : base) cin >> ret;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (base[j] < base[i]) {
        upper[i] = max(upper[i], upper[j]);
      }
    }
    upper[i]++;
  }

  for (int i = 0; i < n; i++) {
    upper[i] = 1;
    for (int j = 0; j < i; j++) {
      if (base[j] < base[i]) upper[i] = max(upper[i], upper[j] + 1);
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    lower[i] = 1;
    for (int j = n - 1; j > i; j--) {
      if (base[j] < base[i]) lower[i] = max(lower[i], lower[j] + 1);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, lower[i] + upper[i]);
  cout << ans - 1;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(101, vector<int>(100'001, -1));
int weight[101];
int value[101];

int func(int idx, int limit) {
  if (idx < 1 || limit < 1) return 0;

  int& ret = dp[idx][limit];
  if (ret != -1) return ret;

  ret = func(idx - 1, limit);

  if (limit - weight[idx] >= 0)
    ret = max(ret, func(idx - 1, limit - weight[idx]) + value[idx]);
  return ret;
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) cin >> weight[i] >> value[i];
  cout << func(n, m);
  return 0;
}

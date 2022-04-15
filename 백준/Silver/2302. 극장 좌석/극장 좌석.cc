#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> arr(41, true);
ll dp[41];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int m;
  cin >> m;

  while (m--) {
    int x;
    cin >> x;
    arr[x] = false;
  }

  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    if (arr[i] && arr[i - 1]) {
      dp[i] = dp[i - 1] + dp[i - 2];
      continue;
    }
    dp[i] = dp[i - 1];
  }
  cout << dp[n];
  return 0;
}

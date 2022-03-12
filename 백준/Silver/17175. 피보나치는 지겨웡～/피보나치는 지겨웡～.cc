#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1'000'000'007;
ll dp[51];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2] + 1) % mod;
  }
  cout << dp[n];
  return 0;
}

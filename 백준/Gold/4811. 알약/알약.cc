#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[31][31];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i <= 30; i++) dp[0][i] = 1;

  for (int w = 1; w <= 30; w++) {
    for (int h = 1; h <= 30; h++) {
      ll ret = 0;
      if (w - 1 >= 0 && (w - 1) <= h) ret += dp[w - 1][h];
      if (h - 1 >= 0 && w <= (h - 1)) ret += dp[w][h - 1];
      dp[w][h] = ret;
    }
  }

  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    cout << dp[n][n] << '\n';
  }
  return 0;
}

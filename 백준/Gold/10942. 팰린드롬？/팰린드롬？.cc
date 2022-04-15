#include <bits/stdc++.h>

using namespace std;

const int MAX = 2002;

vector<vector<bool>> dp(MAX, vector<bool>(MAX));
int arr[MAX];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];

  for (int right = 1; right <= n; right++) {
    for (int left = 1; left <= right; left++) {
      if (left == right) {
        dp[left][right] = true;
        continue;
      }
      if (left + 1 == right) {
        if (arr[left] == arr[right]) dp[left][right] = true;
        continue;
      }
      if (arr[left] == arr[right] && dp[left + 1][right - 1]) {
        dp[left][right] = true;
        continue;
      }
    }
  }

  int m;
  cin >> m;
  while (m--) {
    int st, ed;
    cin >> st >> ed;
    cout << dp[st][ed] << '\n';
  }

  return 0;
}

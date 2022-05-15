#include <bits/stdc++.h>

using namespace std;

const int MAX = 100'001;
int arr[MAX][3];
int dp[MAX][3];

void max_(int n) {
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      int ret = 0;
      if (j - 1 >= 0) ret = max(ret, dp[i - 1][j - 1]);
      ret = max(ret, dp[i - 1][j]);
      if (j + 1 <= 2) ret = max(ret, dp[i - 1][j + 1]);
      dp[i][j] = arr[i][j] + ret;
    }
  }
  cout << *max_element(dp[n - 1], dp[n - 1] + 3);
}
void min_(int n) {
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      int ret = 0xfffff;
      if (j - 1 >= 0) ret = min(ret, dp[i - 1][j - 1]);
      ret = min(ret, dp[i - 1][j]);
      if (j + 1 <= 2) ret = min(ret, dp[i - 1][j + 1]);
      dp[i][j] = arr[i][j] + ret;
    }
  }
  cout << *min_element(dp[n - 1], dp[n - 1] + 3);
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++) cin >> arr[i][j];
  for (int i = 0; i < 3; i++) dp[0][i] = arr[0][i];

  max_(n);
  cout << ' ';
  min_(n);
  return 0;
}
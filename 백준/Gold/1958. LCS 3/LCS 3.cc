#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;

int dp[MAX][MAX][MAX];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str1, str2, str3;
  cin >> str1 >> str2 >> str3;

  int size_1, size_2, size_3;

  size_1 = int(str1.length());
  size_2 = int(str2.length());
  size_3 = int(str3.length());

  str1 = " " + str1;
  str2 = " " + str2;
  str3 = " " + str3;

  for (int i = 1; i <= size_1; i++) {
    for (int j = 1; j <= size_2; j++) {
      for (int k = 1; k <= size_3; k++) {
        if (str1[i] == str2[j] && str2[j] == str3[k]) {
          dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
          continue;
        }
        dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
        dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
      }
    }
  }
  cout << dp[size_1][size_2][size_3];

  return 0;
}
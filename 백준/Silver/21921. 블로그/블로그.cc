#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;

int arr[250'001];
ll dp[250'001];

ll getPsum(int l, int r) {
  ll ret = dp[r];
  if (l > 0) ret -= dp[l - 1];
  return ret;
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int cnt = 0;
  ll maxSum = 0;

  for (int i = 0; i < n; i++) cin >> arr[i];
  dp[0] = arr[0];

  for (int i = 1; i < n; i++) dp[i] = dp[i - 1] + arr[i];

  for (int i = m - 1; i < n; i++) {
    ll ret = getPsum(i - m + 1, i);
    if (maxSum == ret) cnt++;
    if (maxSum < ret) {
      cnt = 1;
      maxSum = ret;
    }
  }
  if (maxSum == 0) cout << "SAD";
  else cout << maxSum << '\n' << cnt;

  return 0;
}
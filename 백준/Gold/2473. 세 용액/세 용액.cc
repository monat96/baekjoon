#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;

const ll MAX = 1e9 + 1;

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<ll> arr(n);
  vector<ll> ans = {MAX, MAX, MAX};
  ll maxSum = ans[0] + ans[1] + ans[2];

  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int idx =
          lower_bound(arr.begin(), arr.end(), -arr[i] - arr[j]) - arr.begin();

      for (int k = -2; k <= 2; k++) {
        if (idx + k == i || idx + k == j) continue;
        if (idx + k < 0 || idx + k >= n) continue;

        ll sum = arr[i] + arr[j] + arr[idx + k];

        if (abs(maxSum) > abs(sum)) {
          maxSum = sum;
          tie(ans[0], ans[1], ans[2]) = {arr[i], arr[j], arr[idx + k]};
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  for(auto ret : ans) cout << ret << ' ';
  return 0;
}
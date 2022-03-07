#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int MAX = 1e4 + 1;
int arr[MAX];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  int ans = 0;

  cin >> n >> s;

  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 1; i < n; i++) arr[i] += arr[i - 1];

  int start = 0, end = 0;
  ll tmpSum;

  while (end < n) {
    tmpSum = start > 0 ? arr[end] - arr[start - 1] : arr[end];
    if (tmpSum <= s) {
      if (tmpSum == s) ans++;
      end++;
    } else
      start++;
  }
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'001;
int arr[MAX];

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int l;
  cin >> l;

  while (l-- > 0) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int cnt = 0, ans = 2e8;
    int left = 0, right = n - 1;
    while (left < right) {
      int summations = arr[left] + arr[right];
      if (abs(summations - k) < abs(ans - k)) {
        ans = summations;
        cnt = 1;
      } else if (abs(summations - k) == abs(ans - k))
        cnt++;

      if (summations > k) {
        right--;
        continue;
      }
      left++;
    }
    cout << cnt << '\n';
  }
  return 0;
}
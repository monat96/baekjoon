#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[10'001];

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  
  sort(arr, arr + n);
  long long ans = 0;

  for(int i = 0; i < n - 2; i++) {
    for(int j = i + 1; j < n - 1; j++) {
      long long temp = -(arr[i] + arr[j]);
      int left = lower_bound(arr + j + 1, arr + n, temp) - arr;
      int right = upper_bound(arr + j + 1, arr + n, temp) - arr;
      ans += (right-left);
    }
  }
  cout << ans;
  return 0;
}
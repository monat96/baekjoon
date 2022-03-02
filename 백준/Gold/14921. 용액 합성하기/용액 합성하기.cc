#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 0xfffff;

int n;
int arr[100'001];

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  int ans = MAX;

  for(int i = 0; i < n; i++) {
    int idx = lower_bound(arr, arr + n, -arr[i]) - arr;

    if(idx + 1 < n && (idx+1) != i && abs(ans) > abs(arr[i] + arr[idx+1]))
      ans = (arr[i] + arr[idx+1]);
    if(idx < n && idx != i && abs(ans) > abs(arr[i] + arr[idx]))
      ans = (arr[i] + arr[idx]);
    if(idx > 0 && (idx-1) != i && abs(ans) > abs(arr[i] + arr[idx-1]))
      ans = (arr[i] + arr[idx-1]);
  }
  cout << ans;
  return 0;
}
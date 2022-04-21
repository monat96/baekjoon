#include <bits/stdc++.h>

using namespace std;

int arr[1'000'001];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int idx = 0;
  while (!cin.eof()) cin >> arr[idx++];
  int ans = count_if(arr, arr + idx, [](int ele) { return ele > 0; });
  cout << ans;
  return 0;
}
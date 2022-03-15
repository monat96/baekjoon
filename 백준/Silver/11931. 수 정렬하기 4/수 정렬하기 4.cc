#include <bits/stdc++.h>

using namespace std;

int arr[1'000'001];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n, greater<>());
  for (int i = 0; i < n; i++) cout << arr[i] << '\n';
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int arr[101];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int g = arr[1] - arr[0];

  for (int i = 2; i < n; i++) g = gcd(g, arr[i] - arr[i - 1]);

  vector<int> ans;
  for (int i = 2; i * i <= g; i++) {
    if (g % i != 0) continue;
    if (i * i != g) ans.push_back(i);
    ans.push_back(g / i);
  }

  sort(ans.begin(), ans.end());
  for (auto ret : ans) cout << ret << ' ';
  cout << g << ' ';
  return 0;
}
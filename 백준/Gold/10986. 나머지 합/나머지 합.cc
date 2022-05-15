#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1e6 + 1;

int arr[MAX];
int psum[MAX];
ll cnt[1'001];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  psum[0] = arr[0] % m;
  for (int i = 1; i < n; i++) psum[i] = (psum[i - 1] % m + arr[i] % m) % m;
  for (int i = 0; i < n; i++) cnt[psum[i]] += 1;
  ll ans = cnt[0];
  for (int i = 0; i < m; i++) ans += (cnt[i] * (cnt[i] - 1)) / 2;
  cout << ans;
  return 0;
}
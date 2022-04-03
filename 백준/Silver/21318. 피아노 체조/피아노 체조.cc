#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[100'001];
int psum[100'001];

int getPsum(int left, int right) {
  int ret = psum[right];
  if (left > 1) ret -= psum[left - 1];
  return ret;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i < n; i++) {
    if (arr[i] > arr[i + 1])
      psum[i] = 1;
    else
      psum[0] = 0;
  }
  for (int i = 2; i <= n; i++) psum[i] += psum[i - 1];
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << getPsum(l, r - 1) << '\n';
  }

  return 0;
}
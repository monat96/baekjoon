#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1005;

void rowSum(int (*arr)[MAX], int n) {
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 1; j <= n; j++) {
      ans += arr[i][j];
    }
    cout << ans << ' ';
  }
  cout << '\n';
}

void colSum(int (*arr)[MAX], int n) {
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 1; j <= n; j++) {
      ans += arr[j][i];
    }
    cout << ans << ' ';
  }
  cout << '\n';
}

void makePsum(int (*arr)[MAX], int n, pair<int, int> p1, pair<int, int> p2,
              int v) {
  int r1, c1, r2, c2;

  tie(r1, c1) = p1;
  tie(r2, c2) = p2;

  arr[r1][c1] += v;
  arr[r2 + 1][c1] -= v;
  arr[r1][c2 + 1] -= v;
  arr[r2 + 1][c2 + 1] += v;
}

void getPsum(int (*arr)[MAX], int (*psum)[MAX], int n) {
  // down
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= n; j++) psum[j][i] += psum[j - 1][i];
  // right
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= n; j++) psum[i][j] += psum[i][j - 1];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) arr[i][j] += psum[i][j];

  rowSum(arr, n);
  colSum(arr, n);
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--) {
    int arr[MAX][MAX] = {0};
    int psum[MAX][MAX] = {0};

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) cin >> arr[i][j];
    while (m--) {
      int r1, c1, r2, c2, v;
      cin >> r1 >> c1 >> r2 >> c2 >> v;

      makePsum(psum, n, {r1, c1}, {r2, c2}, v);
    }
    getPsum(arr, psum, n);
  }

  return 0;
}
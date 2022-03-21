#include <bits/stdc++.h>

using namespace std;

const int SZ = 501;
const int MAX = 1e9;

int maps[SZ][SZ];

int mn = MAX;
int mx = 0;

int check(int lv, int n, int m, int b) {
  int sc = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = maps[i][j] - lv;
      if (x > 0) {
        b += x;
        sc += 2 * x;
      } else if (x < 0) {
        c += -x;
      }
    }
  }
  if (b < c)
    return MAX;
  else
    return sc + c;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, b;
  cin >> n >> m >> b;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> maps[i][j];
      mn = min(mn, maps[i][j]);
      mx = max(mx, maps[i][j]);
    }
  int ans = MAX;
  int mlv = 0;
  for (int i = mx; i >= mn; i--) {
    int sc = check(i, n, m, b);
    if (sc == MAX) continue;
    if (ans > sc) {
      ans = sc;
      mlv = i;
    }
  }
  cout << ans << ' ' << mlv;
  return 0;
}

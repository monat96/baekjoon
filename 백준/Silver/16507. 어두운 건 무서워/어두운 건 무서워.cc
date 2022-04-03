#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1005;

int arr[MAX][MAX];
int psum[MAX][MAX];

void makePsum(int sizeY, int sizeX) {
  for (int i = 1; i <= sizeY; i++) {
    for (int j = 1; j <= sizeX; j++) {
      int ret = arr[i][j];
      if (i > 1) ret += psum[i - 1][j];
      if (j > 1) ret += psum[i][j - 1];
      if (i > 1 && j > 1) ret -= psum[i - 1][j - 1];
      psum[i][j] = ret;
    }
  }
}

int avgPsum(pair<int, int> p1, pair<int, int> p2) {
  int y1, x1, y2, x2;
  tie(y1, x1) = p1;
  tie(y2, x2) = p2;

  int ret = psum[y2][x2];
  if (y1 > 1) ret -= psum[y1 - 1][x2];
  if (x1 > 1) ret -= psum[y2][x1 - 1];
  if (y1 > 1 && x1 > 1) ret += psum[y1 - 1][x1 - 1];

  return ret / ((y2 - y1 + 1) * (x2 - x1 + 1));
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c, q;
  cin >> r >> c >> q;

  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++) cin >> arr[i][j];

  makePsum(r, c);

  while (q--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << avgPsum({y1, x1}, {y2, x2}) << '\n';
  }

  return 0;
}
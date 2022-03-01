#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

#define E 15
#define S 28
#define M 19

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int e, s, m;
  cin >> e >> s >> m;

  if (e == E) e = 0;
  if (s == S) s = 0;
  if (m == M) m = 0;

  int l = lcm(E, lcm(S, M));

  for (int i = s; i <= l; i += S) {
    if (i == 0) continue;
    if (i % E == e && i % S == s && i % M == m) {
      cout << i;
      break;
    }
  }

  return 0;
}

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

void fact(int n) {
  int cnt = 0;
  int div = 2;
  while (n > 1) {
    if (n % div == 0) {
      cnt++;
      n /= div;
      continue;
    }
    if (cnt > 0) {
      cout << div << ' ' << cnt << '\n';
      cnt = 0;
    }
    div++;
  }
  if (cnt != 0) cout << div << ' ' << cnt << '\n';
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while(n--) {
    int x;
    cin >> x;
    fact(x);
  }
  return 0;
}
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b;
  cin >> n >> a >> b;

  int ans = 1;
  while (true) {
    int ta, tb;
    a = (a / 2 + a % 2);
    b = (b / 2 + b % 2);
    if(a == b)
      break;
    ans++;
  }
  cout << ans;
  return 0;
}
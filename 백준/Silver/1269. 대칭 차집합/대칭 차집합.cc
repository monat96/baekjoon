#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> cnt;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;

  cin >> a >> b;

  for (int i = 0; i < a; i++) {
    int x;
    cin >> x;
    cnt[x] += 1;
  }
  int ans = 0;
  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;

    if (cnt[x] > 0) ans++;
  }
  cout << a + b - 2 * ans;
  return 0;
}
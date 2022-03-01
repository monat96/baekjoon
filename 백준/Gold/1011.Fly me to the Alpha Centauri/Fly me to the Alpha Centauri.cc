#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    long long start, dest;
    cin >> start >> dest;
    long long dist = dest - start;
    long long i = 1;
    while (true) {
      if (dist <= i * i) {
        cout << 2 * i - 1 << '\n';
        break;
      }
      if (dist <= i * i + i) {
        cout << 2 * i << '\n';
        break;
      }
      i++;
    }
  }
  return 0;
}

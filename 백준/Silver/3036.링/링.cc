#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

const int MAX = 101;
int arr[MAX];

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  int ret = arr[0];
  for (int i = 1; i < n; i++) {
    int g = gcd(ret, arr[i]);
    cout << ret / g << '/' << arr[i] / g << '\n';
  }

  return 0;
}

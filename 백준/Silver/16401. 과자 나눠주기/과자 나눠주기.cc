#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int arr[1'000'001];
int m, n;

bool func(long long div) {
  int cnt = 0;
  for (int i = 0; i < n; i++) cnt += (arr[i] / div);
  return cnt >= m;
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> m >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  long long left = 0;
  long long right = 1'000'000'000;

  while (left < right) {
    long long mid = (left + right + 1) / 2;

    if (func(mid))
      left = mid;
    else
      right = mid - 1;
  }
  cout << left;
}

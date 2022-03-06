#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;
int mn = 0x7fffffff;
int arr[MAX];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);

  int start = 0, end = 0;
  while (start <= end && end < n) {
    if (arr[end] - arr[start] < m) {
      end++;
      continue;
    }
    if (end == n) break;
    mn = min(mn, arr[end] - arr[start]);
    start++;
  }
  cout << mn;
  return 0;
}

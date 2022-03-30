#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'001;

int arr[MAX];
int lis[MAX];

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  lis[0] = arr[0];

  int len = 1;

  for (int i = 1; i < n; i++) {
    if (arr[i] > lis[len - 1]) {
      lis[len++] = arr[i];
      continue;
    }
    int idx = lower_bound(lis, lis + len, arr[i]) - lis;
    lis[idx] = arr[i];
  }
  cout << len << '\n';
  return 0;
}
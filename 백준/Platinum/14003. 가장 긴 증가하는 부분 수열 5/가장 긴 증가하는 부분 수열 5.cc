#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 1;

int arr[MAX], ans[MAX], ans_idx[MAX];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> arr[i];

  int top = 1;

  ans[0] = arr[0];
  ans_idx[0] = 0;

  for (int i = 1; i < n; i++) {
    int ret = arr[i];
    if (ans[top - 1] < ret) {
      ans[top] = ret;
      ans_idx[i] = top;
      top += 1;
    } else {
      int idx = lower_bound(ans, ans + top, ret) - ans;
      ans[idx] = ret;
      ans_idx[i] = idx;
    }
  }
  cout << top << '\n';
  vector<int> tmp;
  int ret = top - 1;
  for (int i = n - 1; i >= 0; i--)
    if (ans_idx[i] == ret) {
      ret--;
      tmp.push_back(arr[i]);
    }
  for (auto ret = tmp.rbegin(); ret != tmp.rend(); ret++) cout << *ret << ' ';
  return 0;
}
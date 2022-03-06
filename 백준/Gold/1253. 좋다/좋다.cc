#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX = 2005;

int arr[MAX];
map<int, int> cnt;
vector<int> sum;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  int ans = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]] += 1;
  }

  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) continue;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] == 0) continue;
      sum.push_back(arr[i] + arr[j]);
    }
  }
  
  sort(sum.begin(), sum.end());

  for (int i = 0; i < n; i++) {
    if (binary_search(sum.begin(), sum.end(), arr[i])) {
      ans++;
      continue;
    }
    if (arr[i] == 0) {
      if (cnt[0] >= 3) ans++;
      continue;
    }
    if (cnt[0] >= 1 && cnt[arr[i]] >= 2) ans++;
  }
  cout << ans;
  return 0;
}

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int arr[1'000'001];

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> uni;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    uni.push_back(arr[i]);
  }

  sort(uni.begin(), uni.end());
  uni.erase(unique(uni.begin(), uni.end()), uni.end());
  for (int i = 0; i < n; i++) {
    cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << ' ';
  }

  return 0;
}

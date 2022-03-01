#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n;
  
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  sort(arr.begin(), arr.end(), less<>());

  cin >> m;
  for(int i = 0; i < m; i++) {
    int x;
    cin >> x;
    cout << binary_search(arr.begin(), arr.end(), x) << '\n';
  }
  return 0;
}

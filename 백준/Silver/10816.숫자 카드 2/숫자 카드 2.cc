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
  while (m--)
  {
    int x;
    cin >> x;
    cout << upper_bound(arr.begin(), arr.end(), x) - lower_bound(arr.begin(), arr.end(), x) << ' ';
  }
  
  return 0;
}

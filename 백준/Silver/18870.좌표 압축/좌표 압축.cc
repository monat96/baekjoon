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
  vector<int> tmp, uni;
  
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    tmp.push_back(arr[i]);
  }

  sort(tmp.begin(), tmp.end());
  for(int i = 0; i < n; i++) {
    if(i == 0 || tmp[i-1] != tmp[i])
      uni.push_back(tmp[i]);
  }
  for(int i = 0; i < n; i++) {
    cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << ' ';
  }

  return 0;
}

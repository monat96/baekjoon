#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int lowerBound(vector<int> arr, int target) {
  int left = 0;
  int right = int(arr.size());
  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] > target)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr;
  set<int> sArr;

  while (n--) {
    int x;
    cin >> x;
    arr.push_back(x);
    sArr.insert(x);
  }
  vector<int> dArr(sArr.begin(), sArr.end());

  for(auto ret : arr) {
    cout << lower_bound(dArr.begin(), dArr.end(), ret) - dArr.begin() << ' ';  
  }

  return 0;
}

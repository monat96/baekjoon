#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int arr[10'001];

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, target;
  cin >> n >> target;
  for (int i = 0; i < n; i++) cin >> arr[i];

  long long left = 1;
  long long right = 0x7fffffff;
  while(left < right) {
    long long mid = (left + right + 1) / 2;
    
    long long cnt = 0;
    
    for(int i = 0; i < n; i++) cnt += (arr[i] / mid);
    if(cnt >= target) left = mid;
    else right = mid - 1;
  }
  cout << left;
}

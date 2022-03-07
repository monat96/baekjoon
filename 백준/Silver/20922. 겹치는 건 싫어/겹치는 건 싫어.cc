#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[200'001];
int freq[100'001];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];

  int start = 0, end = 0, len = 0;

  while (end < n) {
    while (end < n && freq[arr[end]] < k) {
      freq[arr[end]] += 1;
      end++;
    }
    len = max(len, end - start);
    
    freq[arr[start]] -= 1;
    start++;
  }
  cout << len;
  return 0;
}

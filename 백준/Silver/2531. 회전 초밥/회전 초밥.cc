#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 30'001;

int arr[MAX];
int cnt[MAX];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d, k, c;
  cin >> n >> d >> k >> c;

  for (int i = 0; i < n; i++) cin >> arr[i];

  int start = 0, end = 0;
  int maxCnt = 0;
  int tmpCnt = 0;

  while (start < n) {
    while (end - start < k) {
      cnt[arr[end % n]] += 1;
      if (cnt[arr[end % n]] == 1) tmpCnt++;
      end++;
    }
    if (cnt[c] == 0)
      maxCnt = max(maxCnt, tmpCnt + 1);
    else
      maxCnt = max(maxCnt, tmpCnt);

    cnt[arr[start]] -= 1;
    if (cnt[arr[start]] == 0) tmpCnt--;
    start++;
  }
  cout << maxCnt;
  return 0;
}
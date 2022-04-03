#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[200'001];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  unordered_map<int, int> cnt;

  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 1; i < n; i++) arr[i] += arr[i - 1];

  ll ans = 0;

  // 누적합의 중 0일 경우
  cnt[0]++;

  for (int i = 0; i < n; i++) {
    ans += cnt[arr[i] - k];
    cnt[arr[i]]++;
  }
  cout << ans;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1'000'000'009;
const int MAX = 100'001;
tuple<ll, ll, ll> dp[MAX];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  dp[1] = make_tuple(1, 0, 0);
  dp[2] = make_tuple(0, 1, 0);
  dp[3] = make_tuple(1, 1, 1);

  for (int i = 4; i < MAX; i++) {
    ll a = 0, b = 0, c = 0;

    a += (get<1>(dp[i - 1]) + get<2>(dp[i - 1])) % mod;
    b += (get<0>(dp[i - 2]) + get<2>(dp[i - 2])) % mod;
    c += (get<0>(dp[i - 3]) + get<1>(dp[i - 3])) % mod;
    dp[i] = make_tuple(a, b, c);
  }

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    cout << (get<0>(dp[x]) + get<1>(dp[x]) + get<2>(dp[x])) % mod << '\n';
  }
  return 0;
}

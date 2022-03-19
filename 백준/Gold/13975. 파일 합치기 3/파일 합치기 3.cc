#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int n;
    cin >> n;
    while (n--) {
      int x;
      cin >> x;
      pq.push(x);
    }
    ll ans = 0;
    while (int(pq.size()) > 1) {
      ll a = pq.top();
      pq.pop();
      ll b = pq.top();
      pq.pop();

      ans += a + b;
      pq.push(a + b);
    }
    cout << ans << '\n';
  }

  return 0;
}

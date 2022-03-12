#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1'000'000'007;

ll fib(int n, ll a, ll b) {
  if (n == 0) return a;
  if (n == 1) return b;
  return fib(n - 1, b, (a + b) % mod);
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << fib(n, 0, 1);
  return 0;
}

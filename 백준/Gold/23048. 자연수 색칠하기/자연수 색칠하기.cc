#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> isPrime(n + 1);
  int color = 1;
  isPrime[1] = color++;

  for (int i = 2; i <= n; i++) {
    if (isPrime[i] > 0) continue;
    isPrime[i] = color;
    for (int j = 2 * i; j <= n; j += i) isPrime[j] = color;
    color++;
  }
  cout << color - 1 << '\n';
  for (int i = 1; i <= n; i++) cout << isPrime[i] << ' ';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
vector<bool> isPrime(MAX, true);

void sieve() {
  isPrime[1] = false;
  for (int i = 2; i * i < MAX; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j < MAX; j += i) isPrime[j] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sieve();
  while (true) {
    int n = 0;
    cin >> n;
    if (n == 0) break;
    bool isFlag = false;
    for (int i = 3; i < n; i += 2) {
      if (isPrime[i] && isPrime[n - i]) {
        cout << n << ' ' << '=' << ' ' << i << ' ' << '+' << ' ' << n - i << '\n';
        isFlag = true;
        break;
      }
    }
    if (!isFlag) cout << "Goldbach's conjecture is wrong.\n";
  }
  return 0;
}

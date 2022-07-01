#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll xor_(ll num) {
  int idx = num % 4;
  switch (idx) {
    {
      case 0:
        return num;
      case 1:
        return (num - 1) ^ (num);
      case 2:
        return (num - 2) ^ (num - 1) ^ (num);
      case 3:
        return 0;
      default:
        return -1;
    }
  }
}
ll rangeXor(ll start, ll end) { return (xor_(start - 1) ^ xor_(end)); }
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    ll start, end;
    cin >> start >> end;
    cout << rangeXor(start, end) << '\n';
  }
  return 0;
}
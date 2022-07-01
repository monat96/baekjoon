#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll xor_(ll end) {
  int idx = end % 4;
  switch (idx) {
    {
      case 0:
        return end;
      case 1:
        return (end - 1) ^ (end);
      case 2:
        return (end - 2) ^ (end - 1) ^ (end);
      case 3:
        return 0;
      default:
        return -1;
    }
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll start, end;
  cin >> start >> end;
  cout << (xor_(start - 1) ^ xor_(end));
  return 0;
}
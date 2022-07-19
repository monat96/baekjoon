#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n-- > 0) {
    string ret;
    cin >> ret;
    cout << *ret.begin() << *ret.rbegin() << '\n';
  }
  return 0;
}
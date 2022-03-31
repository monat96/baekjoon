#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  int digit = 0;

  cin >> a >> b;
  cin >> c;

  b += c;
  digit = b / 60;
  b %= 60;
  a = (a + digit) % 24;
  cout << a << ' ' << b;

  return 0;
}

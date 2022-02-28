#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  pair<int, int> f, s;
  
  cin >> f.first >> f.second;
  cin >> s.first >> s.second;

  long long l = lcm(f.second, s.second);
  long long num = f.first * (l/f.second) + s.first * (l/s.second);
  long long g = gcd(num, l);
  
  cout << num / g << ' ' << l / g;

  return 0;
}
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

vector<int> digit;

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string num;
  cin >> num;

  for (auto ch : num) digit.push_back(ch - '0');

  sort(digit.begin(), digit.end(), greater<>());
  int sum = accumulate(digit.begin(), digit.end(), 0);

  if (sum % 3 == 0 && digit.back() == 0)
    for (auto n : digit) cout << n;
  else
    cout << -1;

  return 0;
}
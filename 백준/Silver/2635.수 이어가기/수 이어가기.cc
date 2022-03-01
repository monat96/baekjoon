#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

vector<int> ans;

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    vector<int> pick = {n};
    pick.push_back(i);

    while (true) {
      int sub = *(pick.end() - 2) - *(pick.end() - 1);
      if (sub < 0) break;
      pick.push_back(sub);
    }
    if (int(ans.size()) < int(pick.size())) {
      ans.clear();
      copy(pick.begin(), pick.end(), back_inserter(ans));
    }
  }
  cout << int(ans.size()) << '\n';
  for (auto v : ans) cout << v << ' ';

  return 0;
}

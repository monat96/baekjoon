#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, int> sale;

  int n;
  cin >> n;

  while (n--) {
    string title;
    cin >> title;
    sale[title] += 1;
  }

  auto pr =
      max_element(sale.begin(), sale.end(),
                  [](const pair<string, int>& p1, const pair<string, int>& p2) {
                    if (p1.second == p2.second) return p1.first > p2.first;
                    return p1.second < p2.second;
                  });

  cout << pr->first;
  return 0;
}

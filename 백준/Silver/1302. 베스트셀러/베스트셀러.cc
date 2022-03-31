#include <bits/stdc++.h>

using namespace std;

auto comp = [](const pair<string, int> &p1, const pair<string, int> &p2) {
  if (p1.second == p2.second) return p1.first > p2.first;
  return p1.second < p2.second;
};

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, int> li;

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;
    li[s] += 1;
  }
  auto pr = max_element(li.begin(), li.end(), comp);
  cout << pr->first;

  return 0;
}

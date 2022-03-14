#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  unordered_map<string, vector<string>> member;
  unordered_map<string, string> team;

  while (n--) {
    string teamName;
    int x;

    cin >> teamName;
    cin >> x;

    while (x--) {
      string name;
      cin >> name;
      team[name] = teamName;
      member[teamName].push_back(name);
    }

    sort(member[teamName].begin(), member[teamName].end());
  }
  while (m--) {
    string name;
    int cmd;
    
    cin >> name;
    cin >> cmd;

    if (cmd == 1) {
      cout << team[name] << '\n';
    }
    else if (cmd == 0) {
      for (auto ret : member[name])
        cout << ret << '\n';
    }
  }
  return 0;
}

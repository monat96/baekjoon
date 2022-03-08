#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char arr[9];
vector<int> picked;
vector<bool> isPick(10);

string strMin = "9876543210";
string strMax = "0123456789";

void func(int pick, int toPick) {
  if (pick > 1) {
    int a = *(picked.end() - 2);
    int b = *(picked.end() - 1);
    
    int idx = pick - 2;
    
    if (arr[idx] == '<' && a >= b) return ;
    if (arr[idx] == '>' && a <= b) return ;
  }

  if (pick == toPick) {
    string ret = "";
    for (auto p : picked)
      ret += to_string(p);
    strMin = min(strMin, ret);
    strMax = max(strMax, ret);
  }

  for (int i = 0; i < 10; i++) {
    if (isPick[i]) continue;
    picked.push_back(i);
    isPick[i] = true;

    func(pick + 1, toPick);

    picked.pop_back();
    isPick[i] = false;
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  func(0, n+1);

  cout << strMax << '\n' << strMin << '\n';
  return 0;
}

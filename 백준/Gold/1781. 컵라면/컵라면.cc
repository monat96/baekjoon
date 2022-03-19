#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class comp {
 public:
  bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
  }
};

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
  priority_queue<int, vector<int>, greater<int>> ans;

  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    pq.push({a, b});
  }

  int day = 1;
  int deadline = 0;

  while (!pq.empty()) {
    auto front = pq.top();
    pq.pop();
    if (day < front.first) {
      ans.push(front.second);
      day++;
    } else if (deadline == front.first) {
      if (ans.top() < front.second) {
        ans.pop();
        ans.push(front.second);
      }
    } else {
      ans.push(front.second);
      deadline = front.first;
      day++;
    }
  }

  ll ret = 0;

  while (!ans.empty()) {
    ret += ans.top();
    ans.pop();
  }

  cout << ret;
  return 0;
}

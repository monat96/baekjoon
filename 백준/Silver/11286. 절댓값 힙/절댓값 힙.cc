#include <bits/stdc++.h>

using namespace std;

class comp {
 public:
  bool operator()(const int &a, const int &b) {
    if (abs(a) == abs(b)) return a > b;
    return abs(a) > abs(b);
  }
};

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  priority_queue<int, vector<int>, comp> pq;

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;

    if (x == 0) {
      if (pq.empty())
        cout << 0 << '\n';
      else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else
      pq.push(x);
  }
  return 0;
}

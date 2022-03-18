#include <bits/stdc++.h>

using namespace std;

int arr[1'000'001];

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--) {
    multiset<int> ms;

    int n;
    cin >> n;

    while (n--) {
      char cmd;
      int num;

      cin >> cmd >> num;

      if (cmd == 'I')
        ms.insert(num);
      else {
        if (ms.empty()) continue;
        if (num == 1)
          ms.erase(prev(ms.end()));
        else
          ms.erase(ms.begin());
      }
    }
    if (!ms.empty())
      cout << *(prev(ms.end())) << ' ' << *(ms.begin()) << '\n';
    else
      cout << "EMPTY\n";
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll box[200'001];

ll getPsum(int left, int right) {
  ll ret = box[right];
  if (left > 0) ret -= box[left - 1];
  return ret;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l;
  cin >> n >> l;

  for (int i = 0; i < n; i++) cin >> box[i];
  for (int i = 1; i < n; i++) box[i] += box[i - 1];

  bool isValid = true;
  for (int i = n - 2; i >= 0; i--) {
    ll ret = getPsum(i + 1, n - 1);
    ll th = getPsum(i, i);
    ll top = getPsum(i + 1, i + 1);

    if (top > th + l || top < th - l) {
      isValid = false;
      break;
    }
    if (ret >= (n - i - 1) * (th + l) || ret <= (n - i - 1) * (th - l)) {
      isValid = false;
      break;
    }
  }
  if (isValid)
    cout << "stable";
  else
    cout << "unstable";
  return 0;
}

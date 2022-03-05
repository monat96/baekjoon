#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;

const int MAX = 4001;

int a[MAX], b[MAX], c[MAX], d[MAX];
vector<ll> ab, cd;

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i] >> b[i] >> c[i] >> d[i];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      ab.push_back(a[i] + b[j]);
      cd.push_back(c[i] + d[j]);
    }
  }
  sort(ab.begin(), ab.end());
  sort(cd.begin(), cd.end());
  
  ll ans = 0;
  for(int i = 0; i < int(ab.size()); i++) {
    int target = -ab[i];
    auto range = equal_range(cd.begin(), cd.end(), target);
    ans += range.second - range.first;
  }
  cout << ans;
  return 0;
}
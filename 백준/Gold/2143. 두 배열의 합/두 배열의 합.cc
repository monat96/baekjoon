#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;

const int NN = 1e3 + 1;

vector<ll> makePsum(vector<ll> vec) {
  vector<ll> ret(int(vec.size()));
  ret[0] = vec[0];
  for (int i = 1; i < int(vec.size()); i++) {
    ret[i] = ret[i - 1] + vec[i];
  }
  return ret;
}

ll getPsum(vector<ll> vec, int l, int r) {
  int ret = vec[r];
  if (l > 0) ret -= vec[l-1];
  return ret;
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<ll> vecN, vecM, dpN, dpM, sumN, sumM;
  int target;
  int n, m;
  ll ans = 0;

  cin >> target;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vecN.push_back(x);
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    vecM.push_back(x);
  }

  dpN = makePsum(vecN);
  dpM = makePsum(vecM);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      sumN.push_back(getPsum(dpN, j, i));
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= i; j++) {
      sumM.push_back(getPsum(dpM, j, i));
    }
  }
  
  sort(sumN.begin(), sumN.end());
  sort(sumM.begin(), sumM.end());
  for(int i = 0; i < int(sumN.size()); i++) {
    int tmp = target - sumN[i];
    auto range = equal_range(sumM.begin(), sumM.end(), tmp);
    ans += range.second - range.first;
  }
  cout << ans;
}
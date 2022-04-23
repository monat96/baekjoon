#include <bits/stdc++.h>

using namespace std;

struct info {
  string name;
  int kor;
  int eng;
  int math;
};

bool comp(const info i1, const info i2) {
  if (i1.kor == i2.kor && i1.eng == i2.eng && i1.math == i2.math)
    return i1.name < i2.name;
  if (i1.kor == i2.kor && i1.eng == i2.eng) return i1.math > i2.math;
  if (i1.kor == i2.kor) return i1.eng < i2.eng;
  return i1.kor > i2.kor;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<info> arr(n);
  for (auto &ret : arr) cin >> ret.name >> ret.kor >> ret.eng >> ret.math;
  sort(arr.begin(), arr.end(), comp);
  for (auto ret : arr) cout << ret.name << '\n';
  return 0;
}
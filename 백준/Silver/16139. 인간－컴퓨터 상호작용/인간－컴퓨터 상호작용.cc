#include <bits/stdc++.h>

using namespace std;

const int MAX = 200'001;

int psum[MAX][26];
string arr;

int getPsum(char index, int left, int right) {
  int idx = index - 'a';
  int ret = psum[right][idx];
  if (left > 0) ret -= psum[left - 1][idx];
  return ret;
}

void makePsum(string str) {
  int sz = int(str.length());

  for (int i = 0; i < sz; i++) {
    int idx = arr[i] - 'a';
    psum[i][idx] = 1;
  }

  for (int i = 1; i < sz; i++)
    for (int j = 0; j < 26; j++) psum[i][j] += psum[i - 1][j];
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> arr;
  makePsum(arr);

  int n;
  cin >> n;

  while (n--) {
    char ch;
    int left, right;
    cin >> ch >> left >> right;
    cout << getPsum(ch, left, right) << '\n';
  }
  return 0;
}
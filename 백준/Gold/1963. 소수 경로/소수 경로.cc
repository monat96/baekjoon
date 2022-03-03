#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 10'000;

vector<bool> isPrime(MAX, true);
int dist[MAX];

int vec2num(vector<int> vec) {
  int ret = 0;
  int digit = 1;

  for (auto val : vec) {
    ret += (val * digit);
    digit *= 10;
  }

  return ret;
}
vector<int> num2vec(int num) {
  vector<int> ret;

  while (num > 0) {
    ret.push_back(num % 10);
    num /= 10;
  }

  return ret;
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  isPrime[1] = false;

  for (int i = 2; i * i < MAX; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j < MAX; j += i) isPrime[j] = false;
  }

  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;

    fill(dist, dist + MAX, -1);

    queue<int> que;
    que.push(l);
    dist[l] = 0;

    while (!que.empty()) {
      int curr = que.front();
      que.pop();

      if (curr == r) break;

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
          // 1000미만의 경우
          if (i == 3 && j == 0) continue;

          vector<int> curr2vec = num2vec(curr);
          curr2vec[i] = j;

          int curr2num = vec2num(curr2vec);

          if (!isPrime[curr2num] || dist[curr2num] != -1) continue;

          que.push(curr2num);
          dist[curr2num] = dist[curr] + 1;
        }
      }
    }
    if (dist[r] == -1)
      cout << "Impossible\n";
    else
      cout << dist[r] << '\n';
  }
  return 0;
}
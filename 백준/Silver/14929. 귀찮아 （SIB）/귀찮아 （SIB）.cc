#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

int arr[100'000];

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  long long sum = 0, square_sum = 0;
  while (n--) {
    long long x;
    cin >> x;
    sum += x;
    square_sum += (x * x);
  }
  cout << (sum * sum - square_sum) / 2;
  return 0;
}
#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int arr[1'001];
vector<int> two;

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);

  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) two.push_back(arr[i] + arr[j]);

  sort(two.begin(), two.end());
  two.erase(unique(two.begin(), two.end()), two.end());

  for (int i = n - 1; i > 0; i--)
    for (int j = 0; j < i; j++)
      if (binary_search(two.begin(), two.end(), arr[i] - arr[j])) {
        cout << arr[i];
        return 0;
      }
}

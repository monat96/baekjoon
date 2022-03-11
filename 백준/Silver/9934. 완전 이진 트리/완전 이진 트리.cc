#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX = (1 << 10) + 1;

int arr[MAX];
map<int, vector<int>> tree;

void func(int left, int right, int rank) {
  if (left == right) {
    return;
  }
  int mid = (left + right) / 2;
  tree[rank].push_back(arr[mid]);
  func(left, mid, rank+1);
  func(mid+1, right, rank+1);
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  
  for (int i = 0; i < (1 << n) - 1; i++)
    cin >> arr[i];
  func(0, (1 << n)-1, 1);

  for(auto h : tree) {
    for (auto ele : h.second)
      cout << ele << ' ';
    cout << '\n';
  }
  return 0;
}
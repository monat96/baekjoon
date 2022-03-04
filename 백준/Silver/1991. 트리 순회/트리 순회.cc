#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

map<char, pair<char, char>> tree;

void preorder(char node) {
  if (node == '.') return;
  cout << node;
  preorder(tree[node].first);
  preorder(tree[node].second);
}

void inorder(char node) {
  if (node == '.') return;
  inorder(tree[node].first);
  cout << node;
  inorder(tree[node].second);
}

void postorder(char node) {
  if (node == '.') return;
  postorder(tree[node].first);
  postorder(tree[node].second);
  cout << node;
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n--) {
    char root, left, right;
    cin >> root >> left >> right;
    tree[root] = {left, right};
  }
  preorder('A');
  cout << '\n';
  inorder('A');
  cout << '\n';
  postorder('A');

  return 0;
}
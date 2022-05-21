#include <bits/stdc++.h>

using namespace std;

const int SIZE = 9;

bool isFind = false;
int maps[SIZE][SIZE];
int rowCnt[SIZE][10], colCnt[SIZE][10], areaCnt[SIZE][10];
deque<pair<int, int>> que;

void printSudoko() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) cout << maps[i][j] << ' ';
    cout << '\n';
  }
}
void backTraking() {
  if (isFind) return;
  if (que.empty()) {
    printSudoko();
    isFind = true;
    return;
  }

  int ay, ax;
  tie(ay, ax) = que.front();

  for (int nxt = 1; nxt <= SIZE; nxt++) {
    // invalid
    int areaNum = 3 * (ay / 3) + (ax / 3);
    if (rowCnt[ay][nxt] != 0 || colCnt[ax][nxt] != 0 ||
        areaCnt[areaNum][nxt] != 0)
      continue;
    // valid
    maps[ay][ax] = nxt;
    rowCnt[ay][nxt] = colCnt[ax][nxt] = areaCnt[areaNum][nxt] = 1;
    que.pop_front();

    backTraking();

    if (isFind) break;

    maps[ay][ax] = 0;
    rowCnt[ay][nxt] = colCnt[ax][nxt] = areaCnt[areaNum][nxt] = 0;
    que.push_front({ay, ax});
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++) {
      cin >> maps[i][j];
      if (maps[i][j] == 0) que.push_back({i, j});
      rowCnt[i][maps[i][j]]++;
      colCnt[j][maps[i][j]]++;
      areaCnt[3 * (i / 3) + (j / 3)][maps[i][j]]++;
    }
  backTraking();
  return 0;
}
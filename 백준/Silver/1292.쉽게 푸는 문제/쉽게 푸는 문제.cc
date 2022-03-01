#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1'001;

int arr[MAX];

void makeArr()
{
  int num = 1;
  int idx = 1;
  while(idx < MAX) {
    if(idx + num >= MAX)
      for(int i = idx; i < MAX; i++)
        arr[i] = num;
    else
      for(int i = idx; i < idx + num; i++)
        arr[i] = num;
    idx += num;
    num++;
  }
}

void makePsum()
{
  for(int i = 2; i < MAX; i++) {
    arr[i] += arr[i-1];
  }
}

int getPsum(int a, int b)
{
  int ret = arr[b];
  if(a > 1) ret -= arr[a-1];
  return ret;
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  makeArr();
  makePsum();
  
  int a, b;
  cin >> a >> b;

  cout << getPsum(a, b);
  
  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e6 + 1;

vector<bool> isPrime(MAX);
int arr[MAX];

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  fill(isPrime.begin(), isPrime.end(), true);
  isPrime[1] = false;

  for(int i = 2; i * i < MAX; i++) {
    if(!isPrime[i])
      continue;
    for(int j = i * i; j < MAX; j += i)
      isPrime[j] = false;
  }  
  
  for(int i = 0; i < n; i++) {
    int ans = 0;
    int x = arr[i];
    for(int i = 2; i <= (x / 2); i++) {
      if(!isPrime[i] || !isPrime[x-i])
        continue;
      ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}
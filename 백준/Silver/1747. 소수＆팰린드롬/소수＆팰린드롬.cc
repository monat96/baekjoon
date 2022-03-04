#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

const int NN = 10000000;

vector<bool> isPrime(NN, true);

void sieve() {
  isPrime[1] = false;
  for(int i = 2; i * i < NN; i++) {
    if(!isPrime[i])
      continue;
    for(int j = i * i; j < NN; j += i)
      isPrime[j] = false;
  }
}

bool isPalindrome(int num) {
  int tmp = num;
  int tmpR = 0;
  
  while(num > 0) {
    tmpR = tmpR * 10 + num % 10;
    num /= 10;
  }
  return tmp == tmpR;
}

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  sieve();

  for(int i = n ; i < NN; i++) {
    if(isPrime[i] && isPalindrome(i)) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
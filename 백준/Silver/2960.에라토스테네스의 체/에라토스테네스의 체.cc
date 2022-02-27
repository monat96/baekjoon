#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

vector<bool> isPrime(1'001);
vector<int> primeNum = {0};

void sieve(int n, int k)
{
    for(int i = 2;  i <= n; i++) {
        if(isPrime[i]) continue;
        primeNum.push_back(i);
        for(int j = i * i; j <= n; j += i)
        {
            if(isPrime[j]) continue;
            isPrime[j] = true;
            primeNum.push_back(j);
        }
    }
    cout << primeNum[k];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    sieve(n, k);
    return 0;
}
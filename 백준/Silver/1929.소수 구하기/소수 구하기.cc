#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

vector<bool> isPrime(1000001, true);

void sieve(int n)
{
    isPrime[1] = false;
    for(int i = 2; i * i<= n; i++) {
        if(!isPrime[i]) continue;
        for(int j = i * i; j <= n; j += i)
            isPrime[j] = false;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    sieve(m);
    for(int i = n; i <= m; i++)
        if(isPrime[i]) cout << i << '\n';

    return 0;
}
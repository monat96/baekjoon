#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long fib[1'000'001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n > 0 || (n < 0 && abs(n) % 2 != 0)) cout << 1 << '\n';
    else if(n < 0 && abs(n) % 2 == 0)cout << -1 <<'\n';
    else cout << 0 << '\n';
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= abs(n); i++)
    {
        fib[i] = (fib[i-2] + fib[i-1]) % 1'000'000'000;
    }
    cout << fib[abs(n)];
    return 0;
}
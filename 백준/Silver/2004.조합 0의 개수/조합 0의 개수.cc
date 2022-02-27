#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int func(long long n, int div)
{
    int cnt = 0;
    while(n > 0) {
        cnt += (n/div);
        n /= div;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    int ans = 0;
    cin >> n >> m;
    
    int two = (func(n, 2) - func(m, 2) - func(n - m, 2));
    int five = (func(n, 5) - func(m, 5) - func(n - m, 5));
    cout << min(two, five);

    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[101][10];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 1; i <= 9; i++) dp[1][i] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int k = 0; k <= 9; k++)
        {
            if(k!=0) dp[i][k] += dp[i-1][k-1];
            if(k!=9) dp[i][k] += dp[i-1][k+1];
            dp[i][k] %= 1'000'000'000;
        }
    }
    long long ans = 0;
    for(int i = 0; i < 10; i++)
        ans += dp[n][i];
    cout << ans % 1'000'000'000;
    return 0;
}
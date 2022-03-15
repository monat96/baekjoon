#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dp[31];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    for(int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[2] * dp[i - 2];
        for(int j = 4; j <= i; j += 2)
            dp[i] += 2 * dp[i - j];
    }
    cout << dp[n];
    return 0;
}
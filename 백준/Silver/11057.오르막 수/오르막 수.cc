#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[1'001][11];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    fill(dp[1], dp[1]+11, 1);

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = j; k <= 9; k++) {
                dp[i][j] += (dp[i-1][k] % 10'007);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= 9; i++)
        ans += (dp[n][i] % 10'007);
    cout << ans % 10'007;

    return 0;
}

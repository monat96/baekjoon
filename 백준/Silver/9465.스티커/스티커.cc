#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[2][100'005];
int dp[2][100'005];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[0][i];
        for(int i = 1; i <= n; i++) cin >> arr[1][i];

        dp[0][1] = arr[0][1]; dp[1][1] = arr[1][1];

        for(int i = 2; i <= n; i++)
        {
            int prev_max = max(dp[0][i-2], dp[1][i-2]);
            dp[0][i] = max(prev_max, dp[1][i-1]) + arr[0][i];
            dp[1][i] = max(prev_max, dp[0][i-1]) + arr[1][i];
        }
        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
    return 0;
}
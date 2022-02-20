#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arr[10'001];
int dp[10'001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        fill(dp, dp + 10'001, 0);
        int n, target;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        cin >> target;

        dp[0] = 1;
        
        for(int i = 0; i < n; i++)
            for(int j = arr[i]; j <= target; j++)
                dp[j] += dp[j - arr[i]];
        cout << dp[target] << '\n';
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const long long mod = 1'000'000'009;
long long dp[1'000'001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i = 4; i < 1'000'001; i++)
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % mod;
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
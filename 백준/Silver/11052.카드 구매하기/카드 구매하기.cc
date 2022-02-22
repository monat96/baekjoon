#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

long long card[1'001];
long long dp[1'001];


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> card[i];
    
    dp[1] = card[1];

    for(int i = 2; i <= n; i++) {
        long long mx = card[i];
        for(int j = 1; j < i; j++) {
            mx = max(mx, card[j] + dp[i -j]);
        }
        dp[i] = mx;
    }
    cout << dp[n];
    
    return 0;
}

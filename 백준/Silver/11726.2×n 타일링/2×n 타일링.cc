#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    dp[1] = 1;dp[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i-2] + dp[i-1]) % 10'007;
    }   
    cout << dp[n];
    return 0;
}
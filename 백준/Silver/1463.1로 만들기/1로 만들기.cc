#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i = 2; i <= n; i++)
    {
        int minimum = dp[i-1];
        if(i % 3 == 0) minimum = min(minimum, dp[i/3]);
        if(i % 2 == 0) minimum = min(minimum, dp[i/2]);
        dp[i] = minimum + 1;
    }
    cout << dp[n];
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100'001];
int dp[100'001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 0; i < n; i++) {
        if(arr[i-1] <= arr[i]) {
            dp[i] = dp[i-1] + 1;
            ans = max(ans, dp[i]);
        }
        else dp[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(arr[i-1] >= arr[i]) {
            dp[i] = dp[i-1] + 1;
            ans = max(ans, dp[i]);
        }
        else dp[i] = 1;
    }
    cout << ans;

    return 0;
}
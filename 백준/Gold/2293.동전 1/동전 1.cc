#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[10'001];
int arr[10'001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> arr[i];

    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = arr[i]; j <= m; j++) {
            dp[j] += dp[j - arr[i]];
        }
    }    
    cout << dp[m];

    return 0;
}

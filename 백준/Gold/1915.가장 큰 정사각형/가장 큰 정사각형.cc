#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int arr[1'001][1'0001];
int dp[1'001][1'001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= m; j++)
            arr[i][j] = str[j-1] - '0';
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(arr[i][j] > 0) {
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans * ans;
    return 0;
}

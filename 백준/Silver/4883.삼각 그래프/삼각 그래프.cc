#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 1001

int dp[100'001][3];
int arr[100'001][3];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int tc = 1; ;tc++) {
        int n;
        cin >> n;
        if(n == 0) break;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 3; j++)
                cin >> arr[i][j];
        dp[0][0] = MAX;
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][1] + arr[0][2];

        for(int i = 1; i < n; i++) {
            dp[i][0] = arr[i][0] + min(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = arr[i][1] + min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0]});
            dp[i][2] = arr[i][2] + min({dp[i-1][1], dp[i-1][2], dp[i][1]});
        }
        cout << tc << ". " << dp[n-1][1] <<'\n';
    }
    return 0;
}

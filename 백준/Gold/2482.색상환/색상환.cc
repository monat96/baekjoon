#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 3;
int dp[1001][1001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) dp[i][1] = i;
    for(int i = 4; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            // n 개 중에서 n/2를 초과해서 선택 불가능
            if(j > (i / 2)) break;
            dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % mod;
        }
    }
    cout << dp[n][k];
    return 0;
}

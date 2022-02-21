#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string ans[] = {"SK", "CY"};
int stone[] = {1, 3, 4};
int dp[1001];


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 0;

    for(int i = 5; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(dp[i - stone[j]] == 0)
                dp[i] = 1;
            else {
                dp[i] = 0;
                break;
            }
        }
    }
    cout << ans[dp[n]];
    return 0;
}

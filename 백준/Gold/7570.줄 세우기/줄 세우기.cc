#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1e6 + 1;

int dp[MAX];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int lis = 0;
    int studentNum;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> studentNum;
        dp[studentNum] = dp[studentNum - 1] + 1;
        lis = max(lis, dp[studentNum]);
    }
    cout << n - lis;
    return 0;
}
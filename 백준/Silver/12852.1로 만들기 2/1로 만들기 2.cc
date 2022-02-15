#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int path[1000005];
int dp[1000005];


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for(int i = 2; i <= n; i++)
    {
        int minIdx = i - 1;
        if(i % 2 == 0 && dp[minIdx] > dp[i/2]) minIdx = (i/2);
        if(i % 3 == 0 && dp[minIdx] > dp[i/3]) minIdx = (i/3);

        dp[i] = dp[minIdx] + 1; 
        path[i] = minIdx;
    }
    cout << dp[n] << '\n';
    int idx = n;
    while(true)
    {
        cout << idx << ' ';
        if(idx == 1) break;
        idx = path[idx];
    }
    return 0;
}
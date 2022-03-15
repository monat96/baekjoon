#include <stdio.h>

dp[31];

int main()
{
    int n;
    scanf("%d", &n);
    
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    
    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[2] * dp[i-2];
        for (int j = 4; j <= i; j+=2) {
            dp[i] += 2 * dp[i - j];
        }
    }
    printf("%d", dp[n]);
    return 0;
}
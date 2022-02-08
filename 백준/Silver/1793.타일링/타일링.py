import readline
from sys import stdin

dp = [0] * 251
dp[0] = 1
dp[1] = 1
dp[2] = 3
while(True):
    try:
        n = int(stdin.readline().rstrip())

        for i in range(3, n + 1):
            if dp[i] != 0:
                continue
            dp[i] = 2 * dp[i - 2] + dp[i - 1]
        print(dp[n])
    except:
        break
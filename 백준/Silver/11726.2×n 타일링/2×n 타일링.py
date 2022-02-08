from sys import stdin

if __name__ == '__main__':
    n = int(stdin.readline().rstrip())
    dp = [1, 2]
    for _ in range(2, n):
        dp.append((dp[-1] + dp[-2]) % 10007)
    print(dp[n-1])

from sys import stdin

if __name__ == "__main__":
    n = int(stdin.readline().rstrip())
    coords = []

    for _ in range(n):
        x, y = map(int, stdin.readline().rstrip().split())
        coords.append((x, y))
    ans = 0

    for i in range(n - 1):
        ans += coords[i][0] * coords[i + 1][1] - coords[i][1] * coords[i + 1][0]
    ans += coords[n - 1][0] * coords[0][1] - coords[n - 1][1] * coords[0][0]
    print(round(abs(ans) / 2, 1))

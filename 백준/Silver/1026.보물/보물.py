from sys import stdin

if __name__ == "__main__":
    n = int(stdin.readline().rstrip())
    f = list(map(int, stdin.readline().rstrip().split()))
    s = list(map(int, stdin.readline().rstrip().split()))
    f = sorted(f)
    s = sorted(s, reverse=True)
    print(sum(list(map(lambda x,y: x * y, f, s))))
    
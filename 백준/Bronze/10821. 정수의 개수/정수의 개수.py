from sys import stdin

if __name__ == '__main__':
    arr = list(map(int, stdin.readline().rstrip().split(',')))
    print(len(arr))
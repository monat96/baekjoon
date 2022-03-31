from sys import stdin

if __name__ == "__main__":
    N = int(stdin.readline().rstrip())
    s = set([])
    for _ in range(N):
        name, state = stdin.readline().rstrip().split()
        if state == "enter":
            s.add(name)
            continue
        s.remove(name)
    [print(person) for person in sorted(s, reverse=True)]

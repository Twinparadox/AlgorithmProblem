import sys


def input():
    return sys.stdin.readline().rstrip()


MOD = int(1e9 + 7)
N = int(input())
menu = list(map(int, input().split()))
menu.sort()

result = 0
for i in range(N):
    result += menu[i] * (pow(2, i, MOD) - pow(2, N - i - 1, MOD))

print(result % MOD)

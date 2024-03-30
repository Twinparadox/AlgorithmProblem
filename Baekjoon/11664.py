import sys
import math


def input():
    return sys.stdin.readline().rstrip()


def dist(point1, point2):
    return math.sqrt(sum((p2 - p1) ** 2 for p1, p2 in zip(point1, point2)))


def mid(point1, point2):
    return [(p1 + p2) / 2 for p1, p2 in zip(point1, point2)]


if __name__ == "__main__":
    inputs = list(map(int, input().split()))
    A = inputs[:3]
    B = inputs[3:6]
    C = inputs[6:]

    min_len = 1e9

    while 1:
        len_ac = dist(A, C)
        len_bc = dist(B, C)
        M = mid(A, B)
        len_mc = dist(M, C)

        if abs(min_len - len_mc) <= 1e-6:
            print('{:.10f}'.format(len_mc))
            break

        min_len = min(len_mc, min_len)
        if len_ac < len_bc:
            B = M
            len_bc = len_mc
        else:
            A = M
            len_ac = len_mc

import sys
from fractions import Fraction

def input():
    return sys.stdin.readline().rstrip()


if __name__ == "__main__":
    n = int(input())
    m1, m2 = 1, n ** 2
    v1, v2 = 0, -1e9
    cnt = 0

    while (v2 - v1) < 0:
        new_v1 = Fraction((m1 - m2), (m1 + m2)) * v1 + Fraction((2 * m2), (m1 + m2)) * v2
        new_v2 = Fraction(2 * m1, (m1 + m2)) * v1 - Fraction((m1 - m2), (m1 + m2)) * v2

        v1, v2 = new_v1, new_v2
        cnt += 1

        if v1 < 0:
            cnt += 1
            v1 = -v1

    print(cnt)
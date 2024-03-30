import sys
from collections import Counter

def input():
    return sys.stdin.readline().rstrip()


if __name__ == "__main__":
    n, k = list(map(int, input().split()))
    items = list(map(int, input().split()))

    plugs = []
    remains = Counter(items)
    cnt = 0
    for i, item in enumerate(items):
        if item in plugs:
            remains[item] -= 1
            continue
        if len(plugs) < n:
            plugs.append(item)
            remains[item] -= 1
            continue

        tmp = []
        unplug = False
        for j, plug in enumerate(plugs):
            if plug in items[i:]:
                tmp_idx = items[i:].index(plug)
            else:
                tmp_idx = 101
                unplug = True

            tmp.append(tmp_idx)
            if unplug:
                break

        remove_item = tmp.index(max(tmp))
        del plugs[remove_item]
        plugs.append(item)
        remains[item] -= 1
        cnt += 1

    print(cnt)
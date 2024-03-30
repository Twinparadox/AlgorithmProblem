import sys
def input():
    return sys.stdin.readline().rstrip()


class SegmentTree:
    def __init__(self, n, arr):
        self.n = n
        self.arr = arr
        self.tree = [0] * (4 * n)
        self.make_tree(0, n - 1, 1)

    def make_tree(self, node_left, node_right, idx):
        if node_left == node_right:
            self.tree[idx] = (self.arr[node_left], node_left)
            return self.tree[idx]

        mid = (node_left + node_right) // 2
        left, left_idx = self.make_tree(node_left, mid, 2 * idx)
        right, right_idx = self.make_tree(mid + 1, node_right, 2 * idx + 1)

        if left < right:
            self.tree[idx] = (left, left_idx)
        elif left > right:
            self.tree[idx] = (right, right_idx)
        else:
            self.tree[idx] = (left, min(left_idx, right_idx))

        return self.tree[idx]

    def find_min_value(self, left, right, idx, node_left, node_right):
        if right < node_left or left > node_right:
            return int(1e10), 100001
        if left <= node_left and node_right <= right:
            return self.tree[idx]

        mid = (node_left + node_right) // 2
        left_val, left_idx = self.find_min_value(left, right, 2 * idx, node_left, mid)
        right_val, right_idx = self.find_min_value(left, right, 2 * idx + 1, mid + 1, node_right)

        if left_val < right_val:
            return left_val, left_idx
        elif left_val > right_val:
            return right_val, right_idx
        else:
            return left_val, min(left_idx, right_idx)

    def update_tree(self, node_left, node_right, node_idx, index, new_value):
        if index < node_left or index > node_right:
            return self.tree[node_idx]
        if node_left == node_right:
            self.tree[node_idx] = new_value, index
            return self.tree[node_idx]

        mid = (node_left + node_right) // 2
        left_val, left_idx = self.update_tree(node_left, mid, 2 * node_idx, index, new_value)
        right_val, right_idx = self.update_tree(mid + 1, node_right, 2 * node_idx + 1, index, new_value)

        if left_val < right_val:
            self.tree[node_idx] = (left_val, left_idx)
        elif left_val > right_val:
            self.tree[node_idx] = (right_val, right_idx)
        else:
            self.tree[node_idx] = (left_val, min(left_idx, right_idx))

        return self.tree[node_idx]

    def get_value(self, i, j):
        return self.find_min_value(i, j, 1, 0, self.n - 1)

    def update_value(self, i, v):
        self.arr[i] = v;
        return self.update_tree(0, self.n - 1, 1, i, v)


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    segment_tree = SegmentTree(n, arr)

    for _ in range(int(input())):
        q, a, b = map(int, input().split())
        if q == 1:
            segment_tree.update_value(a - 1, b)
        else:
            val, index = segment_tree.get_value(a - 1, b - 1)
            print(index + 1)

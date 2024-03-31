# Link: https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1

from typing import Optional
from collections import deque


class Node:
    def _init_(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.my_counter = 0
        self.index = 0

    def merge(self, a, p, q, r):
        l = q - p + 1
        a1 = a[p : q + 1]
        l2 = r - q
        a2 = a[q + 1 : r + 1]

        left = 0
        right = 0
        k = p

        while left < l and right < l2:
            if a1[left] <= a2[right]:
                a[k] = a1[left]
                left += 1
            else:
                a[k] = a2[right]
                right += 1

                self.my_counter += l - left
            k += 1

        while left < l:
            a[k] = a1[left]
            k += 1
            left += 1

        while right < l2:
            a[k] = a2[right]
            k += 1
            right += 1

    def mergeSort(self, a, p, r):
        if p < r:
            q = (p + r) // 2
            self.mergeSort(a, p, q)
            self.mergeSort(a, q + 1, r)
            self.merge(a, p, q, r)

    def inversionCount(self, arr):
        n = len(arr)
        self.mergeSort(arr, 0, n - 1)
        res = self.my_counter
        self.my_counter = 0
        return res

    def inOrderStorage(self, root, arr):
        if root is not None:
            self.inOrderStorage(root.left, arr)
            arr.append(root.data)
            self.inOrderStorage(root.right, arr)

    def pairsViolatingBST(self, n: int, root: Optional["Node"]):
        arr = []
        self.inOrderStorage(root, arr)
        return self.inversionCount(arr)


if __name__ == "__main__":
    root = Node(5)
    root.left = Node(3)
    root.right = Node(6)
    root.left.left = Node(2)
    root.left.right = Node(4)
    root.right.right = Node(7)
    obj = Solution()
    print(obj.pairsViolatingBST(6, root))

# Link: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

import heapq


class Solution:
    def kthSmallest(self, arr, k):
        n = len(arr)

        pq = []

        for i in range(k):
            heapq.heappush(pq, -arr[i])
        for i in range(k, n):
            if arr[i] < -pq[0]:
                heapq.heappop(pq)
                heapq.heappush(pq, -arr[i])
        return -pq[0]


if __name__ == "__main__":
    obj = Solution()
    arr = [7, 10, 4, 3, 20, 15]
    k = 3
    print(obj.kthSmallest(arr, k))

    arr = [7, 10, 4, 20, 15]
    k = 4
    print(obj.kthSmallest(arr, k))

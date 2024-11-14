# Link: https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

import heapq


class Solution:
    def nearlySorted(self, arr, k):
        n = len(arr)
        pq = []

        for i in range(k + 1):
            heapq.heappush(pq, arr[i])

        temp = k + 1

        for i in range(n):
            arr[i] = heapq.heappop(pq)
            if temp < n:
                heapq.heappush(pq, arr[temp])
            temp += 1


if __name__ == "__main__":
    object = Solution()
    arr = [6, 5, 3, 2, 8, 10, 9]
    k = 3
    object.nearlySorted(arr, k)
    print(" ".join(map(str, arr)))

    arr = [1, 4, 5, 2, 3, 6, 7, 8, 9, 10]
    k = 2
    object.nearlySorted(arr, k)
    print(" ".join(map(str, arr)))

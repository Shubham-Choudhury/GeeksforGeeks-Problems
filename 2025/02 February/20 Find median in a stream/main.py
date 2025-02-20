# Link: https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

import heapq


class Solution:
    def getMedian(self, arr):
        h1, h2, r = [], [], []
        for i in arr:
            heapq.heappush(h1, -heapq.heappushpop(h2, i))
            if len(h1) > len(h2):
                heapq.heappush(h2, -heapq.heappop(h1))
            r.append((-h1[0] + h2[0]) / 2.0 if len(h1) == len(h2) else h2[0])
        return r


if __name__ == "__main__":
    obj = Solution()
    arr = [5, 15, 1, 3, 2, 8]
    medians = obj.getMedian(arr)
    print(" ".join(map(str, medians)))

    arr = [2, 2, 2, 2]
    medians = obj.getMedian(arr)
    print(" ".join(map(str, medians)))

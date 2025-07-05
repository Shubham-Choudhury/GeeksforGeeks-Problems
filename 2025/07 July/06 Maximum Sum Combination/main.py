# Link: https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

import heapq


class Solution:
    def topKSumPairs(self, a, b, k):
        n = len(a)

        a.sort(reverse=True)
        b.sort(reverse=True)

        visited = set()
        heap = []

        heapq.heappush(heap, (-(a[0] + b[0]), 0, 0))

        visited.add((0, 0))

        res = []

        while len(res) < k:
            sum_neg, i, j = heapq.heappop(heap)
            res.append(-sum_neg)

            if i + 1 < n and (i + 1, j) not in visited:
                heapq.heappush(heap, (-(a[i + 1] + b[j]), i + 1, j))
                visited.add((i + 1, j))

            if j + 1 < n and (i, j + 1) not in visited:
                heapq.heappush(heap, (-(a[i] + b[j + 1]), i, j + 1))
                visited.add((i, j + 1))

        return res


if __name__ == "__main__":
    sol = Solution()
    a = [3, 2]
    b = [1, 4]
    k = 2
    result = sol.topKSumPairs(a, b, k)
    print(result)

    a = [1, 4, 2, 3]
    b = [2, 5, 1, 6]
    k = 3
    result = sol.topKSumPairs(a, b, k)
    print(result)

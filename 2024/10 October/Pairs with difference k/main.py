# Link: https://www.geeksforgeeks.org/problems/pairs-with-difference-k1713/1

from collections import defaultdict


class Solution:
    def countPairsWithDiffK(self, arr, k):
        ans = 0
        mp = defaultdict(int)

        for x in arr:
            ans += mp[x - k]
            ans += mp[x + k]
            mp[x] += 1

        return ans


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 5, 3, 4, 2]
    k = 3
    print(obj.countPairsWithDiffK(arr, k))

    arr = [8, 12, 16, 4, 0, 20]
    k = 4
    print(obj.countPairsWithDiffK(arr, k))

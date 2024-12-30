# Link: https://www.geeksforgeeks.org/problems/majority-vote/1

from collections import defaultdict


class Solution:
    def findMajority(self, arr):
        n = len(arr)
        mp = defaultdict(int)
        ans = []
        for num in arr:
            mp[num] += 1
        target = n // 3
        for key, value in mp.items():
            if value > target:
                ans.append(key)
        ans.sort()
        return ans


if __name__ == "__main__":
    object = Solution()
    arr = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
    ans = object.findMajority(arr)
    print(" ".join(map(str, ans)))

    arr = [1, 2, 3, 4, 5]
    ans = object.findMajority(arr)
    print(" ".join(map(str, ans)))

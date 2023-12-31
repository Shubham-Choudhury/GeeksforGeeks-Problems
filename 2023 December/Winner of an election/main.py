# Link: https://www.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1

from collections import defaultdict


class Solution:
    def winner(self, arr, n):
        mp = defaultdict(int)
        for name in arr:
            mp[name] += 1
        maxy = max(mp.values())
        ans = []
        for x, y in mp.items():
            if y == maxy:
                ans.append([x, y])
        if len(ans) == 1:
            return ans[0]
        ans.sort()
        return ans[0]


if __name__ == "__main__":
    obj = Solution()
    arr = [
        "john",
        "johnny",
        "jackie",
        "johnny",
        "john",
        "jackie",
        "jamie",
        "jamie",
        "john",
        "johnny",
        "jamie",
        "johnny",
        "john",
    ]
    n = len(arr)
    print(obj.winner(arr, n))

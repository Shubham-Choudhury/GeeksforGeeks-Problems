# Link: https://www.geeksforgeeks.org/problems/in-first-but-second5423/1

class Solution:
    def findMissiong(self, a, b, n, m):
        res = []
        mp = {}
        for i in range(m):
            mp[b[i]] = 1

        for i in range(n):
            if a[i] not in mp:
                res.append(a[i])
        return res
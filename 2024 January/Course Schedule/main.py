# Link: https://www.geeksforgeeks.org/problems/course-schedule/1


class Solution:
    def findOrder(self, n, m, prerequisites):
        from collections import defaultdict

        g = defaultdict(set)
        indeg = defaultdict(int)
        for sto, sta in prerequisites:
            g[sta].add(sto)
            indeg[sto] += 1
        q = [sto for sto in range(n) if indeg[sto] == 0]
        ans = []
        while q:
            cur = q.pop()
            ans.append(cur)
            for nxt in g[cur]:
                indeg[nxt] -= 1
                if indeg[nxt] == 0:
                    q.append(nxt)
        if len(ans) == n:
            return ans
        else:
            return []


if __name__ == "__main__":
    obj = Solution()
    n = 2
    m = 1
    prerequisites = [[1, 0]]
    print(obj.findOrder(n, m, prerequisites))
    n = 4
    m = 4
    prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
    print(obj.findOrder(n, m, prerequisites))

# Link: https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1


class Solution:
    def findMinCost(self, x, y, costX, costY):
        m, n = len(x), len(y)
        prv = [0 for _ in range(m + 1)]
        cur = [0 for _ in range(m + 1)]
        for b in range(1, n + 1):
            for a in range(1, m + 1):
                if x[a - 1] == y[b - 1]:
                    cur[a] = prv[a - 1] + 1
                cur[a] = max(cur[a], prv[a], cur[a - 1])
            prv = cur[:]
        mx = cur[-1]
        return (m - mx) * costX + (n - mx) * costY


if __name__ == "__main__":
    obj = Solution()
    x = "ef"
    y = "gh"
    costX = 10
    costY = 20
    print(obj.findMinCost(x, y, costX, costY))

    x = "abcd"
    y = "acdb"
    costX = 10
    costY = 20
    print(obj.findMinCost(x, y, costX, costY))

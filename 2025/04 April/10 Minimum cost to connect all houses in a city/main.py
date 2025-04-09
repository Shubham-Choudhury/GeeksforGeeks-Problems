# Link: https://www.geeksforgeeks.org/problems/minimum-cost-to-connect-all-houses-in-a-city/1


class Solution:
    def minCost(self, houses):
        n = len(houses)
        inMST = [False] * n
        minDist = [float("inf")] * n
        minDist[0] = 0
        totalCost = 0

        for i in range(n):
            u = -1
            for j in range(n):
                if not inMST[j] and (u == -1 or minDist[j] < minDist[u]):
                    u = j

            totalCost += minDist[u]
            inMST[u] = True

            for v in range(n):
                if not inMST[v]:
                    dist = abs(houses[u][0] - houses[v][0]) + abs(
                        houses[u][1] - houses[v][1]
                    )
                    if dist < minDist[v]:
                        minDist[v] = dist

        return totalCost


if __name__ == "__main__":
    sol = Solution()
    houses = [[0, 7], [0, 9], [20, 7], [30, 7], [40, 70]]
    print(sol.minCost(houses))

    houses = [[0, 0], [1, 1], [1, 3], [3, 0]]
    print(sol.minCost(houses))

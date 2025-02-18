# Link: https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1


class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        def dfs(x, y):
            return (x**2) + (y**2)

        distance = []

        for x, y in points:
            dist = dfs(x, y)
            distance.append([dist, [x, y]])
        sorted_dist = sorted(distance)

        return [sorted_dist[i][1] for i in range(k)]


if __name__ == "__main__":
    object = Solution()
    points = [[1, 3], [-2, 2], [5, 8], [0, 1]]
    k = 2
    result = object.kClosest(points, k)
    for p in result:
        print(p[0], p[1])
    print()

    points = [[2, 4], [-1, -1], [0, 0]]
    k = 1
    result = object.kClosest(points, k)
    for p in result:
        print(p[0], p[1])
    print()

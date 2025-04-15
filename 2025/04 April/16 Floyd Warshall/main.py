# Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1


class Solution:
    def floydWarshall(self, dist):
        for k in range(len(dist)):
            for i in range(len(dist)):
                for j in range(len(dist)):
                    if dist[i][j] > dist[i][k] + dist[k][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
        return dist


if __name__ == "__main__":
    obj = Solution()
    dist = [
        [0, 4, 10**8, 5, 10**8],
        [10**8, 0, 1, 10**8, 6],
        [2, 10**8, 0, 3, 10**8],
        [10**8, 10**8, 1, 0, 2],
        [1, 10**8, 10**8, 4, 0],
    ]
    result = obj.floydWarshall(dist)
    for row in result:
        print(row)
    print()

    dist = [[0, -1, 2], [1, 0, 10**8], [3, 1, 0]]
    result = obj.floydWarshall(dist)
    for row in result:
        print(row)

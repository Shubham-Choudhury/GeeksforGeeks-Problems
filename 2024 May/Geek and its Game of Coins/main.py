# Link: https://www.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1


class Solution:
    def findWinner(self, n: int, x: int, y: int) -> int:
        d = [True] * (n + 1)
        for i in range(2, n + 1):
            d[i] = (
                i - x == 0
                or i - y == 0
                or (i - 1 > 0 and not d[i - 1])
                or (i - x > 0 and not d[i - x])
                or (i - y > 0 and not d[i - y])
            )
        return int(d[n])


if __name__ == "__main__":
    obj = Solution()
    n = 5
    x = 3
    y = 4
    print(obj.findWinner(n, x, y))

    n = 2
    x = 3
    y = 4
    print(obj.findWinner(n, x, y))

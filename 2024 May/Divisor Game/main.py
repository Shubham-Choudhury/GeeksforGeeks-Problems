# Link: https://www.geeksforgeeks.org/problems/divisor-game-1664432414/1


class Solution:
    def divisorGame(self, n):
        return n % 2 == 0


if __name__ == "__main__":
    obj = Solution()
    n = 2
    print(obj.divisorGame(n))
    n = 3
    print(obj.divisorGame(n))

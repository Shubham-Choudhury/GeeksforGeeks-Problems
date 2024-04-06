# Link: https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1


class Solution:
    def countWays(self, n):
        mod = 1000000007
        output = 0
        for x in range(n + 1):
            if (n - x) & 1 == 0:
                output += 1
        return output


if __name__ == "__main__":
    obj = Solution()
    n = 4
    print(obj.countWays(n))
    n = 5
    print(obj.countWays(n))

# Link: https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1


class Solution:
    def TotalWays(self, N):
        mod = 10**9 + 7
        prev, curr = 1, 1
        for i in range(N):
            prev, curr = curr, (prev + curr) % mod
        return (curr * curr) % mod


if __name__ == "__main__":
    obj = Solution()
    N = 1
    print(obj.TotalWays(N))
    N = 3
    print(obj.TotalWays(N))

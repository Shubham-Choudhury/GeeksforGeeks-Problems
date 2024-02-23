# Link: https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1


class Solution:
    def maxSum(self, n):
        def div(n):
            if n >= n // 2 + n // 3 + n // 4:
                return n
            return div(n // 2) + div(n // 3) + div(n // 4)

        return div(n)


if __name__ == "__main__":
    obj = Solution()
    n = 12
    print(obj.maxSum(n))
    n = 24
    print(obj.maxSum(n))

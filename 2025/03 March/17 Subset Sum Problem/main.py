# Link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1


class Solution:
    def isSubsetSum(self, arr, sum):
        n = len(arr)

        ans = [[False for i in range(sum + 1)] for _ in range(n)]

        for k in range(n):
            ans[k][0] = True
        if arr[0] <= sum:
            ans[0][arr[0]] = True

        for i in range(1, n):
            for j in range(1, sum + 1):
                if j - arr[i] >= 0:
                    ans[i][j] = ans[i - 1][j] or ans[i - 1][j - arr[i]]
                else:
                    ans[i][j] = ans[i - 1][j]
        return ans[n - 1][sum]


if __name__ == "__main__":
    obj = Solution()
    arr = [3, 34, 4, 12, 5, 2]
    sum = 9
    print(obj.isSubsetSum(arr, sum))

    arr = [3, 34, 4, 12, 5, 2]
    sum = 30
    print(obj.isSubsetSum(arr, sum))

    arr = [1, 2, 3]
    sum = 6
    print(obj.isSubsetSum(arr, sum))

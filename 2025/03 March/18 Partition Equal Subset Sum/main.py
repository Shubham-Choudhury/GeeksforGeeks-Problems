# Link: https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1


class Solution:
    def equalPartition(self, arr):
        total = sum(arr)
        if total % 2 == 1:
            return False

        target = total // 2

        dp = [False] * (target + 1)
        dp[0] = True

        for n in arr:
            for i in range(len(dp) - 1, n - 1, -1):
                if dp[i]:
                    continue
                if dp[i - n]:
                    dp[i] = True
                if dp[-1]:
                    return True

        return False


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 5, 11, 5]
    print(obj.equalPartition(arr))
    arr = [1, 3, 5]
    print(obj.equalPartition(arr))

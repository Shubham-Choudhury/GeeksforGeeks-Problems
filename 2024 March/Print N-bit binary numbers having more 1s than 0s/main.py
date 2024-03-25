# Link: https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1


class Solution:
    def NBitBinary(self, n):
        ans = []
        self.backtrack(["1"], 1, n, ans)
        return ans

    def backtrack(self, arr, i, n, ans):
        if len(arr) == n:
            ans.append("".join(arr))
        else:
            arr.append("1")
            self.backtrack(arr, i + 1, n, ans)
            if i > 0:
                arr[-1] = "0"
                self.backtrack(arr, i - 1, n, ans)
            arr.pop()


if __name__ == "__main__":
    obj = Solution()
    n = 2
    print(obj.NBitBinary(n))
    n = 3
    print(obj.NBitBinary(n))

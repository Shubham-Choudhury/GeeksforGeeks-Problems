# Link: https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1


class Solution:
    def LCSof3(self, A, B, C, n1, n2, n3):
        dp = [[[0] * (n3 + 1) for _ in range(n2 + 1)] for _ in range(n1 + 1)]
        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                for k in range(1, n3 + 1):
                    if A[i - 1] == B[j - 1] == C[k - 1]:
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1
                    else:
                        dp[i][j][k] = max(
                            dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]
                        )
        return dp[-1][-1][-1]


if __name__ == "__main__":
    obj = Solution()
    A = "geeks"
    B = "geeksfor"
    C = "geeksforgeeks"
    print(obj.LCSof3(A, B, C, len(A), len(B), len(C)))
    A = "abcd"
    B = "efgh"
    C = "ijkl"
    print(obj.LCSof3(A, B, C, len(A), len(B), len(C)))

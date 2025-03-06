# Link: https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1


class Solution:
    def lcs(self, s1, s2):
        x = len(s1)
        y = len(s2)

        matrix = [[0] * (y + 1) for q in range(x + 1)]
        for i in range(1, x + 1):
            for j in range(1, y + 1):
                if s1[i - 1] == s2[j - 1]:
                    matrix[i][j] = matrix[i - 1][j - 1] + 1
                else:
                    matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
        return matrix[x][y]


if __name__ == "__main__":
    obj = Solution()
    s1 = "ABCDGH"
    s2 = "AEDFHR"
    print(obj.lcs(s1, s2))

    s1 = "ABC"
    s2 = "AC"
    print(obj.lcs(s1, s2))

    s1 = "XYZW"
    s2 = "XYWZ"
    print(obj.lcs(s1, s2))

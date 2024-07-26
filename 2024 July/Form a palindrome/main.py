# Link: https://www.geeksforgeeks.org/problems/form-a-palindrome1455/1


class Solution:
    def countMin(self, str):
        n = len(str)
        palin = [[0] * n for _ in range(n)]

        for gap in range(1, n):
            for j in range(n - gap):
                i = j + gap
                if str[i] == str[j]:
                    palin[j][i] = palin[j + 1][i - 1]
                else:
                    palin[j][i] = min(palin[j + 1][i], palin[j][i - 1]) + 1

        return palin[0][n - 1]


if __name__ == "__main__":
    obj = Solution()
    str = "abcd"
    print(obj.countMin(str))

    str = "aa"
    print(obj.countMin(str))

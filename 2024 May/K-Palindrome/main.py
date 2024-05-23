# Link: https://www.geeksforgeeks.org/problems/find-if-string-is-k-palindrome-or-not1923/1


class Solution:
    def kPalindrome(self, str, n, k):
        prev = [0] * n
        for i in range(n - 1, -1, -1):
            curr = [0] * n
            curr[i] = 1
            for j in range(i + 1, n):
                curr[j] = max(prev[j], curr[j - 1])
                if str[i] == str[j]:
                    curr[j] = max(curr[j], 2 + prev[j - 1])
            prev = [l for l in curr]
        return 1 if n - curr[n - 1] <= k else 0


if __name__ == "__main__":
    obj = Solution()
    str = "abcdecba"
    k = 1
    n = len(str)
    print(obj.kPalindrome(str, n, k))

    str = "abcdefcba"
    k = 1
    n = len(str)
    print(obj.kPalindrome(str, n, k))

# Link: https://www.geeksforgeeks.org/problems/substrings-with-similar-first-and-last-characters3644/1


class Solution:
    def countSubstring(self, s):
        n = len(s)
        freq = [0] * 26

        for i in range(n):
            freq[ord(s[i]) - ord("a")] += 1

        count = 0

        for i in range(26):
            count += (freq[i] * (freq[i] + 1)) // 2

        return count


if __name__ == "__main__":
    obj = Solution()
    s = "abcab"
    result = obj.countSubstring(s)
    print(result)
    s = "aba"
    result = obj.countSubstring(s)
    print(result)

# Link: https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1


class Solution:
    def longestUniqueSubstr(self, s: str) -> int:
        mp = {}
        start = 0
        n = len(s)
        maxLen = 0
        for i in range(n):
            if s[i] in mp and mp[s[i]] >= start:
                start = mp[s[i]] + 1
            mp[s[i]] = i
            maxLen = max(maxLen, i - start + 1)
        return maxLen


if __name__ == "__main__":
    object = Solution()
    s = "geeksforgeeks"
    print(object.longestUniqueSubstr(s))

    s = "aaa"
    print(object.longestUniqueSubstr(s))

    s = "abcdefabcbb"
    print(object.longestUniqueSubstr(s))

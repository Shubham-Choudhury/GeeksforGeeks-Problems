# Link: https://www.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring3421/1


class Solution:
    def longestSubstring(self, s, n):
        max_length = 0
        ans = "-1"
        i, j = 0, 0
        while i < n and j < n:
            sub_string = s[i : j + 1]
            if s.find(sub_string, j + 1) != -1:
                length = len(sub_string)
                if length > max_length:
                    ans = sub_string
                    max_length = length
            else:
                i += 1
            j += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    s = "acdcdacdc"
    n = len(s)
    print(obj.longestSubstring(s, n))
    s = "heheheh"
    n = len(s)
    print(obj.longestSubstring(s, n))

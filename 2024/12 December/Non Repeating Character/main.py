# Link: https://www.geeksforgeeks.org/problems/non-repeating-character-1587115620/1

from collections import defaultdict


class Solution:
    def non_repeating_char(self, s):
        n = len(s)
        mp = defaultdict(int)

        for it in s:
            mp[it] += 1

        for i in range(n):
            if mp[s[i]] == 1:
                return s[i]
        return "$"


if __name__ == "__main__":
    object = Solution()
    s = "geeksforgeeks"
    print(object.non_repeating_char(s))
    s = "racecar"
    print(object.non_repeating_char(s))
    s = "aabbccc"
    print(object.non_repeating_char(s))

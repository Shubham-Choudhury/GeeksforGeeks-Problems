# Link: https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1

from collections import defaultdict


class Solution:
    def smallestSubstring(self, S):
        ans = 100000
        count = [0] * 3
        flag = 0
        i, j = 0, 0
        while i < len(S):
            if 0 in count and j < len(S):
                temp = int(S[j])
                count[temp] += 1
                j = j + 1
            else:
                if 0 not in count:
                    flag = 1
                    ans = min(ans, j - i)
                    if ans == 3:
                        return 3
                    temp = int(S[i])
                    count[temp] -= 1
                i = i + 1
        if flag == 0:
            return -1
        return ans


if __name__ == "__main__":
    obj = Solution()
    S = "01212"
    print(obj.smallestSubstring(S))

# Link: // Link: https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

import sys
from collections import defaultdict


class Solution:
    def smallestWindow(self, s, p):
        n = len(s)
        m = len(p)

        if n < m:
            return "-1"

        target = defaultdict(int)
        for ch in p:
            target[ch] += 1

        start = 0
        min_len = sys.maxsize
        min_start = 0
        count = 0
        window = defaultdict(int)

        for end in range(n):
            current_char = s[end]
            window[current_char] += 1

            if current_char in target and window[current_char] <= target[current_char]:
                count += 1

            while count == m:
                window_len = end - start + 1

                if window_len < min_len:
                    min_len = window_len
                    min_start = start

                start_char = s[start]
                window[start_char] -= 1

                if start_char in target and window[start_char] < target[start_char]:
                    count -= 1

                start += 1

        if min_len == sys.maxsize:
            return "-1"

        return s[min_start : min_start + min_len]


if __name__ == "__main__":
    obj = Solution()
    s = "timetopractice"
    p = "toc"
    print(obj.smallestWindow(s, p))

    s = "zoomlazapzo"
    p = "oza"
    print(obj.smallestWindow(s, p))

# Link: https://www.geeksforgeeks.org/problems/help-nobita0532/1

from collections import defaultdict


class Solution:
    def oddEven(self, s: str) -> str:
        d = defaultdict(int)
        for i in s:
            d[i] += 1
        ans = 0
        for i in set(s):
            if (ord(i) - 96) % 2 == d[i] % 2:
                ans += 1
        if ans % 2 == 0:
            return "EVEN"
        return "ODD"


if __name__ == "__main__":
    obj = Solution()
    s = "abbbcc"
    print(obj.oddEven(s))

    s = "nobitaa"
    print(obj.oddEven(s))

# Link: https://www.geeksforgeeks.org/problems/remaining-string3515/1


class Solution:
    def printString(self, s: str, ch: str, count: int) -> str:
        c = 0
        for i in range(len(s)):
            if s[i] == ch:
                c += 1
            if c == count:
                return s[i + 1 :]
        return ""


if __name__ == "__main__":
    obj = Solution()
    s = "Thisisdemostring"
    ch = "i"
    count = 3
    print(obj.printString(s, ch, count))

    s = "Thisisdemostri"
    ch = "i"
    count = 3
    print(obj.printString(s, ch, count))

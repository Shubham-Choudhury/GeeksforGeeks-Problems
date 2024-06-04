# Link: https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1


class Solution:
    def binaryNextNumber(self, s: str) -> str:
        i = len(s) - 1
        while i >= 0 and s[i] != "0":
            s = s[:i] + "0" + s[i + 1 :]
            i -= 1
        if i >= 0:
            s = s[:i] + "1" + s[i + 1 :]
        else:
            s = "1" + s

        i = 0
        while i < len(s) and s[i] == "0":
            i += 1

        return s[i:]


if __name__ == "__main__":
    obj = Solution()
    s = "10"
    print(obj.binaryNextNumber(s))
    s = "111"
    print(obj.binaryNextNumber(s))

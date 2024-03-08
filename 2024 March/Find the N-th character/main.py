# Link: https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1


class Solution:
    def nthCharacter(self, s, r, n):
        f = 1
        fl = 0
        while r:
            fl = n >> 1
            if 2 * fl == n:
                f = int(not (f ^ 1))
            else:
                f = int(not (f ^ 0))
            n >>= 1
            r -= 1
        if f == 0:
            return str(int(not int(s[fl])))
        else:
            return s[fl]


if __name__ == "__main__":
    obj = Solution()
    s = "1100"
    r = 2
    n = 3
    print(obj.nthCharacter(s, r, n))
    s = "1010"
    r = 1
    n = 2
    print(obj.nthCharacter(s, r, n))

# Link: https://www.geeksforgeeks.org/problems/implement-atoi/1


class Solution:
    def atoi(self, s):
        if s[0] == "-":
            s = s[1:]
            if s.isnumeric() == False:
                return -1
            else:
                num = 0
                for i in s:
                    digit = ord(i) - ord("0")
                    num = num * 10 + digit
                return -1 * num
        else:
            if s.isnumeric() == False:
                return -1
            else:
                num = 0
                for i in s:
                    digit = ord(i) - ord("0")
                    num = num * 10 + digit
                return num


if __name__ == "__main__":
    obj = Solution()
    s = "-123"
    print(obj.atoi(s))
    s = "21a"
    print(obj.atoi(s))
    s = "123"
    print(obj.atoi(s))

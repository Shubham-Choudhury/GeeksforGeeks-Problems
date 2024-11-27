# Link: https://www.geeksforgeeks.org/problems/implement-atoi/1


class Solution:
    def myAtoi(self, s):
        s = s.strip()

        if not s:
            return 0

        sign = 1
        result = 0
        index = 0

        if s[0] == "-":
            sign = -1
            index += 1
        elif s[0] == "+":
            index += 1

        while index < len(s) and s[index].isdigit():
            result = result * 10 + int(s[index])
            index += 1

        result *= sign

        int_min, int_max = -(2**31), 2**31 - 1
        if result < int_min:
            return int_min
        if result > int_max:
            return int_max

        return result


if __name__ == "__main__":
    object = Solution()
    s = "123"
    print(object.myAtoi(s))
    s = "  -"
    print(object.myAtoi(s))
    s = " 1231231231311133"
    print(object.myAtoi(s))
    s = "-999999999999"
    print(object.myAtoi(s))
    s = "  -0012gfg4"
    print(object.myAtoi(s))

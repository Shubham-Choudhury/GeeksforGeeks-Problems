# Link: https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1


class Solution:
    def value(self, r):
        if r == "I":
            return 1
        if r == "V":
            return 5
        if r == "X":
            return 10
        if r == "L":
            return 50
        if r == "C":
            return 100
        if r == "D":
            return 500
        if r == "M":
            return 1000
        return -1

    def romanToDecimal(self, s):
        res = 0
        i = 0
        while i < len(s):
            s1 = self.value(s[i])

            if i + 1 < len(s):
                s2 = self.value(s[i + 1])

                if s1 >= s2:
                    res = res + s1
                    i = i + 1
                else:
                    res = res + s2 - s1
                    i = i + 2
            else:
                res = res + s1
                i = i + 1

        return res


if __name__ == "__main__":
    sol = Solution()
    s = "IX"
    result = sol.romanToDecimal(s)
    print(f"The integer value of the Roman numeral '{s}' is: {result}")

    s = "XL"
    result = sol.romanToDecimal(s)
    print(f"The integer value of the Roman numeral '{s}' is: {result}")

    s = "MCMIV"
    result = sol.romanToDecimal(s)
    print(f"The integer value of the Roman numeral '{s}' is: {result}")

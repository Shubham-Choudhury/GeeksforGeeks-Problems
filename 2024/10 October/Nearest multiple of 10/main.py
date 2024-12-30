# Link: https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1


class Solution:
    def roundToNearest(self, s):
        n = len(s)
        if int(s[n - 1]) <= 5:
            s = s[:-1] + "0"
            return s

        carry = 1
        s = s[:-1] + "0"
        for i in range(n - 2, -1, -1):
            if carry:
                num = int(s[i]) + 1
                carry = num // 10
                s = s[:i] + str(num % 10) + s[i + 1 :]
            else:
                break

        if carry:
            s = str(carry) + s

        return s


if __name__ == "__main__":
    obj = Solution()
    s = "29"
    print(obj.roundToNearest(s))
    s = "15"
    print(obj.roundToNearest(s))

# Link: https://www.geeksforgeeks.org/problems/multiply-two-strings/1


class Solution:
    def multiplyStrings(self, s1, s2):
        def remove_leading_zeros(s):
            i = 0
            while i < len(s) and s[i] == "0":
                i += 1
            return s[i:] if i < len(s) else "0"

        sign = 1
        if s1[0] == "-":
            sign *= -1
            s1 = s1[1:]
        if s2[0] == "-":
            sign *= -1
            s2 = s2[1:]

        s1 = remove_leading_zeros(s1)
        s2 = remove_leading_zeros(s2)

        if s1 == "0" or s2 == "0":
            return "0"

        res = [0] * (len(s1) + len(s2))

        for i in range(len(s1) - 1, -1, -1):
            for j in range(len(s2) - 1, -1, -1):
                mul = (ord(s1[i]) - ord("0")) * (ord(s2[j]) - ord("0"))
                p1 = i + j
                p2 = i + j + 1
                sum_ = mul + res[p2]

                res[p2] = sum_ % 10
                res[p1] += sum_ // 10

        result = ""
        for num in res:
            if not (len(result) == 0 and num == 0):
                result += chr(num + ord("0"))

        if sign == -1:
            result = "-" + result

        return result


if __name__ == "__main__":
    obj = Solution()
    s1 = "0033"
    s2 = "2"
    print(obj.multiplyStrings(s1, s2))
    s1 = "11"
    s2 = "23"
    print(obj.multiplyStrings(s1, s2))
    s1 = "123"
    s2 = "0"
    print(obj.multiplyStrings(s1, s2))

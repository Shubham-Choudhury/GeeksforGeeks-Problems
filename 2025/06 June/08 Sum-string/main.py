# Link: https://www.geeksforgeeks.org/problems/sum-string3151/1

class Solution:
    def string_sum(self, str1, str2):
        if len(str1) < len(str2):
            str1, str2 = str2, str1

        m, n = len(str1), len(str2)
        ans = ""
        carry = 0

        for i in range(n):
            ds = ((ord(str1[m - 1 - i]) - ord('0')) +
                  (ord(str2[n - 1 - i]) - ord('0')) + carry) % 10

            carry = ((ord(str1[m - 1 - i]) - ord('0')) +
                     (ord(str2[n - 1 - i]) - ord('0')) + carry) // 10

            ans = chr(ds + ord('0')) + ans

        for i in range(n, m):
            ds = (ord(str1[m - 1 - i]) - ord('0') + carry) % 10
            carry = (ord(str1[m - 1 - i]) - ord('0') + carry) // 10
            ans = chr(ds + ord('0')) + ans

        if carry:
            ans = chr(carry + ord('0')) + ans

        return ans

    def checkSumStrUtil(self, string, beg, len1, len2):
        s1 = string[beg:beg + len1]
        s2 = string[beg + len1:beg + len1 + len2]

        if (len(s1) > 1 and s1[0] == '0') or (len(s2) > 1 and s2[0] == '0'):
            return False

        s3 = self.string_sum(s1, s2)
        s3_len = len(s3)

        if s3_len > len(string) - len1 - len2 - beg:
            return False

        s3_part = string[beg + len1 + len2:beg + len1 + len2 + s3_len]

        if len(s3_part) > 1 and s3_part[0] == '0':
            return False

        if s3 == s3_part:
            if beg + len1 + len2 + s3_len == len(string):
                return True

            return self.checkSumStrUtil(string, beg + len1, len2, s3_len)

        return False

    def isSumStr(self, string):
        n = len(string)

        for i in range(1, n):
            for j in range(1, n - i):
                if self.checkSumStrUtil(string, 0, i, j):
                    return True

        return False

    def isSumString(self, S):
        return self.isSumStr(S)
    
if __name__ == "__main__":
    obj = Solution()
    s = "12243660"
    print(obj.isSumString(s))

    s = "1111112223"
    print(obj.isSumString(s))

    s = "123456"
    print(obj.isSumString(s))
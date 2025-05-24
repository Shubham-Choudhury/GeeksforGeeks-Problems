# Link: https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1


class Solution:
    def sumSubstrings(self, s):
        sum = 0
        mf = 1
        for i in range(len(s) - 1, -1, -1):
            sum = sum + (int(s[i])) * (i + 1) * mf
            mf = mf * 10 + 1

        return sum


if __name__ == "__main__":
    obj = Solution()
    s = "6759"
    print(obj.sumSubstrings(s))

    s = "421"
    print(obj.sumSubstrings(s))

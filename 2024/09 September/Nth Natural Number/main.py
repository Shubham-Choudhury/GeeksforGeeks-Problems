# Link: https://www.geeksforgeeks.org/problems/nth-natural-number/1


class Solution:
    def findNth(self, n):
        res = 0
        multi = 1
        while n > 0:
            rem = n % 9
            res += multi * rem
            n //= 9
            multi *= 10
        return res


if __name__ == "__main__":
    obj = Solution()
    n = 8
    print(obj.findNth(n))
    n = 9
    print(obj.findNth(n))

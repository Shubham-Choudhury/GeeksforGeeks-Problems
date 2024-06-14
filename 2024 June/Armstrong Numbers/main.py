# Link: https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1


class Solution:
    def armstrongNumber(self, n):
        d1 = n // 100
        d2 = (n // 10) % 10
        d3 = n % 10

        total = d1**3 + d2**3 + d3**3

        if total == n:
            return "Yes"
        else:
            return "No"


if __name__ == "__main__":
    obj = Solution()
    print(obj.armstrongNumber(153))
    print(obj.armstrongNumber(370))
    print(obj.armstrongNumber(372))

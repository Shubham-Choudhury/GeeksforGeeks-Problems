# Link: https://www.geeksforgeeks.org/problems/minimum-sum4058/1


class Solution:
    def minSum(self, arr):
        arr.sort()
        a1, a2 = [], []

        i = 0
        while i < len(arr):
            a1.append(arr[i])
            i += 1
            if i < len(arr):
                a2.append(arr[i])
                i += 1

        a1.reverse()
        a2.reverse()

        ans = []
        i = 0
        j = 0
        carry = 0

        while i < len(a1) and j < len(a2):
            digit = a1[i] + a2[j] + carry
            carry = digit // 10
            digit %= 10
            ans.append(digit)
            i += 1
            j += 1

        while i < len(a1):
            digit = a1[i] + carry
            carry = digit // 10
            digit %= 10
            ans.append(digit)
            i += 1

        while j < len(a2):
            digit = a2[j] + carry
            carry = digit // 10
            digit %= 10
            ans.append(digit)
            j += 1

        while carry:
            digit = carry
            carry = digit // 10
            digit %= 10
            ans.append(digit)

        ans.reverse()
        i = 0
        while i < len(ans) and ans[i] == 0:
            i += 1

        if i == len(ans):
            return "0"

        res = ""
        while i < len(ans):
            res += str(ans[i])
            i += 1

        return res


if __name__ == "__main__":
    object = Solution()
    arr = [6, 8, 4, 5, 2, 3]
    print(object.minSum(arr))

    arr = [5, 3, 0, 7, 4]
    print(object.minSum(arr))

    arr = [9, 4]
    print(object.minSum(arr))

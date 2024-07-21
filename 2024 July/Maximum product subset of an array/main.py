# Link: https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1


class Solution:
    def findMaxProduct(self, arr):
        mod = int(1e9 + 7)
        arr.sort()
        n = len(arr)
        zero = 0
        neg = 0
        pos = 0

        ans = 1

        for val in arr:
            if val > 0:
                ans = (ans * val) % mod
            if val == 0:
                zero += 1
            elif val < 0:
                neg += 1
            else:
                pos += 1

        if neg // 2:
            finalVal = neg % 2
            for val in arr:
                if val < 0 and neg > finalVal:
                    ans = (ans * val + mod) % mod
                    neg -= 1

        if pos == 0 and ans == 1:
            if zero:
                ans = 0
            else:
                ans = max(arr)

        return (ans + mod) % mod


if __name__ == "__main__":
    obj = Solution()
    arr = [-1, 0, -2, 4, 3]
    print(obj.findMaxProduct(arr))

    arr = [-1, 0]
    print(obj.findMaxProduct(arr))

    arr = [5]
    print(obj.findMaxProduct(arr))

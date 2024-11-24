# Link: https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1


class Solution:
    def maxProduct(self, arr):
        n = len(arr)
        p = 1
        s = 1
        ans = float("-inf")
        for i in range(n):
            if p == 0:
                p = 1
            if s == 0:
                s = 1
            p *= arr[i]
            s *= arr[n - i - 1]

            ans = max(ans, max(p, s))
        return ans


if __name__ == "__main__":
    object = Solution()
    arr = [-2, 6, -3, -10, 0, 2]
    print(object.maxProduct(arr))

    arr = [-1, -3, -10, 0, 60]
    print(object.maxProduct(arr))

    arr = [2, 3, 4]
    print(object.maxProduct(arr))

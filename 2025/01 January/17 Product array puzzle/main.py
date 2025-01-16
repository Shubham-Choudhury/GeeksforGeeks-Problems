# Link: https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1


class Solution:
    def productExceptSelf(self, arr):
        n = len(arr)
        result = [1] * n
        left = right = 1
        for i in range(n):
            result[i] *= left
            left *= arr[i]
            result[~i] *= right
            right *= arr[~i]
        return result


if __name__ == "__main__":
    obj = Solution()
    arr = [10, 3, 5, 6, 2]
    print(obj.productExceptSelf(arr))

    arr = [12, 0]
    print(obj.productExceptSelf(arr))

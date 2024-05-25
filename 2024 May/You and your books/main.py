# Link: https://www.geeksforgeeks.org/problems/you-and-your-books/1


class Solution:
    def max_Books(self, arr, n, k):
        ans = 0
        curr = 0
        for i in range(n):
            if arr[i] <= k:
                curr += arr[i]
            else:
                curr = 0
            ans = max(ans, curr)
        return ans


if __name__ == "__main__":
    obj = Solution()
    arr1 = [3, 2, 2, 3, 1, 1, 1, 3]
    n = len(arr1)
    k = 1
    print(obj.max_Books(arr1, n, k))

    arr2 = [3, 2, 2, 3, 1, 1, 1, 3]
    n = len(arr2)
    k = 2
    print(obj.max_Books(arr2, n, k))

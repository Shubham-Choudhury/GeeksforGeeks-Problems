# Link: https://www.geeksforgeeks.org/problems/second-largest3735/1


class Solution:
    def getSecondLargest(self, arr):
        maxi = max(arr)
        ans = -1
        for it in arr:
            if it < maxi:
                ans = max(ans, it)
        return ans


if __name__ == "__main__":
    object = Solution()
    arr = [12, 35, 1, 10, 34, 1]
    print(object.getSecondLargest(arr))

    arr = [10, 5, 10]
    print(object.getSecondLargest(arr))

    arr = [10, 10, 10]
    print(object.getSecondLargest(arr))

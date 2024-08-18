# Link: https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1


class Solution:
    def canSplit(self, arr):
        total_sum = sum(arr)
        temp = 0

        for num in arr:
            temp += num
            total_sum -= num

            if temp == total_sum:
                return True

        return False


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 4, 5, 5]
    print(obj.canSplit(arr))

    arr = [4, 3, 2, 1]
    print(obj.canSplit(arr))

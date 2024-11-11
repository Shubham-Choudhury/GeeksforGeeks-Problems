# Link: https://www.geeksforgeeks.org/problems/attend-all-meetings/1


class Solution:
    def canAttend(self, arr):
        arr.sort()

        for i in range(1, len(arr)):
            if arr[i][0] < arr[i - 1][1]:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    arr = [[1, 4], [10, 15], [7, 10]]
    print(obj.canAttend(arr))

    arr = [[2, 4], [9, 12], [6, 10]]
    print(obj.canAttend(arr))

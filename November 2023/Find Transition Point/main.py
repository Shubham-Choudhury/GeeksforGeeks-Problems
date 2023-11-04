# Link: https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1


class Solution:
    def transitionPoint(self, arr, n):
        for i in range(0, n):
            if arr[i] == 1:
                return i

        return -1


if __name__ == "__main__":
    obj = Solution()
    arr = [0, 0, 0, 1, 1]
    n = len(arr)
    print(obj.transitionPoint(arr, n))

    arr = [0, 0, 0, 0]
    n = len(arr)
    print(obj.transitionPoint(arr, n))

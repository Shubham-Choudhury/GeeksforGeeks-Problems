# Link: https://www.geeksforgeeks.org/problems/roof-top-1587115621/1


class Solution:
    def maxStep(self, arr):
        n = len(arr)
        max_steps = 0
        currentsteps = 0

        for i in range(n - 1):
            if arr[i + 1] > arr[i]:
                currentsteps += 1
            else:
                currentsteps = 0
            max_steps = max(currentsteps, max_steps)
        return max_steps


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 2, 3, 2]
    print(obj.maxStep(arr))

    arr = [1, 2, 3, 4]
    print(obj.maxStep(arr))

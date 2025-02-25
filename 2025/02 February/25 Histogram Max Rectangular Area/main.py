# Link: https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1


class Solution:
    def getMaxArea(self, arr):
        n = len(arr)
        stack = []
        ans = 0

        for i in range(n + 1):
            while stack and (i == n or arr[stack[-1]] >= arr[i]):
                height = arr[stack.pop()]
                width = i if not stack else (i - stack[-1] - 1)
                ans = max(ans, height * width)
            stack.append(i)

        return ans


if __name__ == "__main__":
    obj = Solution()
    arr = [60, 20, 50, 40, 10, 50, 60]
    print(obj.getMaxArea(arr))

    arr = [3, 5, 1, 7, 5, 9]
    print(obj.getMaxArea(arr))

    arr = [3]
    print(obj.getMaxArea(arr))

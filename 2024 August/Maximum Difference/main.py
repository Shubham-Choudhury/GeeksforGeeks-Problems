# Link: https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1


class Solution:
    def findMaxDiff(self, arr):
        n = len(arr)
        right = []
        s1 = []
        for i in range(n - 1, -1, -1):
            if not s1:
                right.append(0)
            else:
                while s1 and arr[s1[-1]] >= arr[i]:
                    s1.pop()
                if not s1:
                    right.append(0)
                else:
                    right.append(arr[s1[-1]])
            s1.append(i)
        right.reverse()

        left = []
        s2 = []
        for i in range(n):
            if not s2:
                left.append(0)
            else:
                while s2 and arr[s2[-1]] >= arr[i]:
                    s2.pop()
                if not s2:
                    left.append(0)
                else:
                    left.append(arr[s2[-1]])
            s2.append(i)

        maxDiff = float("-inf")
        for i in range(n):
            maxDiff = max(maxDiff, abs(right[i] - left[i]))
        return maxDiff


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 1, 8]
    print(obj.findMaxDiff(arr))
    arr = [2, 4, 8, 7, 7, 9, 3]
    print(obj.findMaxDiff(arr))

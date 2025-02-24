# Link: https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1


class Solution:
    def calculateSpan(self, arr):
        n = len(arr)
        ans = [1] * n
        s = []

        for i in range(n):
            while s and arr[s[-1]] <= arr[i]:
                ans[i] += ans[s.pop()]
            s.append(i)
        return ans


if __name__ == "__main__":
    object = Solution()
    arr = [100, 80, 60, 70, 60, 75, 85]
    ans = object.calculateSpan(arr)
    print(" ".join(map(str, ans)))

    arr = [10, 4, 5, 90, 120, 80]
    ans = object.calculateSpan(arr)
    print(" ".join(map(str, ans)))

    arr = [11, 4, 5, 90, 120, 80]
    ans = object.calculateSpan(arr)
    print(" ".join(map(str, ans)))

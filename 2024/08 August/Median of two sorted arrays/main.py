# Link: https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1


class Solution:
    def SumofMiddleElements(self, arr1, arr2):
        n = len(arr1)
        i = 0
        j = 0
        ct = 1
        while i < n and j < n and ct <= n:
            if arr1[i] <= arr2[j]:
                i += 1
            else:
                j += 1
            ct += 1
        rt = min(arr1[min(n - 1, i)], arr2[min(n - 1, j)])
        lf = max(arr1[max(i - 1, 0)], arr2[max(j - 1, 0)])
        return lf + rt


if __name__ == "__main__":
    obj = Solution()
    arr1 = [1, 2, 4, 6, 10]
    arr2 = [4, 5, 6, 9, 12]
    print(obj.SumofMiddleElements(arr1, arr2))

    arr1 = [1, 12, 15, 26, 38]
    arr2 = [2, 13, 17, 30, 45]
    print(obj.SumofMiddleElements(arr1, arr2))

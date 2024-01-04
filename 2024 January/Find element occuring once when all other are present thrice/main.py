# Link: https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1


class Solution:
    def singleElement(self, arr, N):
        d = {}
        for i in arr:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        for i in d:
            if d[i] == 1:
                return i


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 10, 1, 1]
    n = len(arr)
    print(obj.singleElement(arr, n))

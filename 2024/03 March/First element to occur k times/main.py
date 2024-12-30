# Link: https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1


class Solution:
    def firstElementKTime(self, a, n, k):
        d = {}
        for i in a:
            if i not in d:
                d[i] = 1
            else:
                d[i] = d[i] + 1
            if d[i] == k:
                return i
        return -1


if __name__ == "__main__":
    obj = Solution()
    n = 7
    k = 2
    a = [1, 7, 4, 3, 4, 8, 7]
    print(obj.firstElementKTime(a, n, k))

# Link: https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1


class Solution:
    def lis(self, arr):
        sub = []
        for i in arr:
            l, r = 0, len(sub)
            while l < r:
                m = (l + r) // 2
                if sub[m] < i:
                    l = m + 1
                else:
                    r = m
            if l == len(sub):
                sub.append(i)
            else:
                sub[l] = i
        return len(sub)


if __name__ == "__main__":
    object = Solution()
    arr = [5, 8, 3, 7, 9, 1]
    print(object.lis(arr))

    arr = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
    print(object.lis(arr))

    arr = [3, 10, 2, 1, 20]
    print(object.lis(arr))

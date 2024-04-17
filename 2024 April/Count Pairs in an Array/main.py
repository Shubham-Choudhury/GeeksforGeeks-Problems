# Link: https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1


class Solution:
    def countPairs(self, arr, n):
        from sortedcontainers import SortedList

        A = [i * v for i, v in enumerate(arr)]
        S = SortedList()
        ans = 0
        while A:
            v = A.pop()
            ix = S.bisect_left(v)
            ans += ix
            S.add(v)
        return ans


if __name__ == "__main__":
    obj = Solution()
    arr = [8, 4, 2, 1]
    n = len(arr)
    print(obj.countPairs(arr, n))
    arr = [5, 0, 10, 2, 4, 1, 6]
    n = len(arr)
    print(obj.countPairs(arr, n))

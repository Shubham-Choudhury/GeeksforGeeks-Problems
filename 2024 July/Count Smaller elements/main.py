# Link: https://www.geeksforgeeks.org/problems/count-smaller-elements2214/1

from bisect import bisect_left


class Solution:
    def constructLowerArray(self, arr):
        n = len(arr)
        if n == 0:
            return []

        ans = []
        sorted_arr = [arr[-1]]
        ans.append(0)

        for i in range(n - 2, -1, -1):
            idx = bisect_left(sorted_arr, arr[i])
            ans.append(idx)
            sorted_arr.insert(idx, arr[i])

        return ans[::-1]


if __name__ == "__main__":
    obj = Solution()
    arr = [12, 1, 2, 3, 0, 11, 4]
    ans = obj.constructLowerArray(arr)
    print(ans)

    arr = [1, 2, 3, 4, 5]
    ans = obj.constructLowerArray(arr)
    print(ans)

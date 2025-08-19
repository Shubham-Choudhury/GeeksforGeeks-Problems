# Link: https://www.geeksforgeeks.org/problems/farthest-smaller-right/1


class Solution:
    def farMin(self, arr):
        n = len(arr)
        ans = [-1] * n

        suff = arr.copy()
        suff[n - 1] = arr[n - 1]
        for i in range(n - 2, -1, -1):
            suff[i] = min(arr[i], suff[i + 1])

        for i in range(n):
            lo, hi, res = i + 1, n - 1, -1

            while lo <= hi:
                mid = (lo + hi) // 2
                if suff[mid] < arr[i]:
                    res = mid
                    lo = mid + 1
                else:
                    hi = mid - 1

            ans[i] = res

        return ans


if __name__ == "__main__":
    sol = Solution()
    arr = [2, 5, 1, 3, 2]
    result = sol.farMin(arr)
    print(result)

    arr = [2, 3, 5, 4, 1]
    result = sol.farMin(arr)
    print(result)

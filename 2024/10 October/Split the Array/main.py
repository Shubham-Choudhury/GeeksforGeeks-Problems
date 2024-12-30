# Link: https://www.geeksforgeeks.org/problems/split-the-array0238/1


class Solution:
    def countgroup(self, arr):
        n = len(arr)
        ans = 0
        mod = 10**9 + 7
        for i in range(n):
            ans ^= arr[i]
        val = 1
        for i in range(n - 1):
            val *= 2
            val %= mod
        return val - 1 if ans == 0 else 0


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3]
    print(obj.countgroup(arr))

    arr = [5, 2, 3, 2]
    print(obj.countgroup(arr))

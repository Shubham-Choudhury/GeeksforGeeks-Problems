# Link: https://www.geeksforgeeks.org/problems/max-min-height--170647/1


class Solution:
    def isPossible(self, arr, k, w, maxHeight):
        n = len(arr)
        water = [0] * n

        for i in range(n):
            if i > 0:
                water[i] = water[i - 1]

            currHeight = arr[i] + water[i]

            if i >= w:
                currHeight -= water[i - w]

            if currHeight < maxHeight:
                add = maxHeight - currHeight
                water[i] += add
                k -= add

                if k < 0:
                    return False

        return True

    def maxMinHeight(self, arr, k, w):
        n = len(arr)

        low = arr[0]
        for i in range(1, n):
            if arr[i] < low:
                low = arr[i]

        high = low + k
        ans = low

        while low <= high:
            mid = low + (high - low) // 2

            if self.isPossible(arr, k, w, mid):
                ans = max(ans, mid)
                low = mid + 1
            else:
                high = mid - 1

        return ans


if __name__ == "__main__":
    sol = Solution()
    arr = [2, 3, 4, 5, 1]
    k = 2
    w = 2
    result = sol.maxMinHeight(arr, k, w)
    print(f"Maximum minimum height: {result}")

    arr = [5, 8]
    k = 5
    w = 1
    result = sol.maxMinHeight(arr, k, w)
    print(f"Maximum minimum height: {result}")

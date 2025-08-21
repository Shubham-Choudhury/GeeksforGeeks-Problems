# Link: https://www.geeksforgeeks.org/problems/maximize-the-minimum-difference-between-k-elements/1


class Solution:
    def isPossible(self, arr, k, mid):
        count = 1
        last = arr[0]

        for i in range(1, len(arr)):
            if arr[i] - last >= mid:
                count += 1
                last = arr[i]
            if count == k:
                return True

        return False

    def maxMinDiff(self, arr, k):
        arr.sort()

        low = 0
        high = arr[-1] - arr[0]
        answer = 0

        while low <= high:
            mid = (low + high) // 2

            if self.isPossible(arr, k, mid):
                answer = mid
                low = mid + 1
            else:
                high = mid - 1

        return answer


if __name__ == "__main__":
    sol = Solution()
    arr = [2, 6, 2, 5]
    k = 3
    result = sol.maxMinDiff(arr, k)
    print(f"Maximum minimum difference for {k} elements: {result}")

    arr = [1, 4, 9, 0, 2, 13, 3]
    k = 4
    result = sol.maxMinDiff(arr, k)
    print(f"Maximum minimum difference for {k} elements: {result}")

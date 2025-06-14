# Link: https://www.geeksforgeeks.org/problems/smallest-divisor/1


class Solution:
    def smallestDivisor(self, arr, k):
        low = 1
        high = max(arr)
        res = -1

        while low <= high:
            mid = low + (high - low) // 2
            total = 0

            for ele in arr:
                total += (ele + mid - 1) // mid

            if total <= k:
                res = mid
                high = mid - 1
            else:
                low = mid + 1

        return res


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 5, 9]
    k = 6
    result = sol.smallestDivisor(arr, k)
    print(f"The smallest divisor is: {result}")

    arr = [1, 1, 1, 1]
    k = 4
    result = sol.smallestDivisor(arr, k)
    print(f"The smallest divisor is: {result}")

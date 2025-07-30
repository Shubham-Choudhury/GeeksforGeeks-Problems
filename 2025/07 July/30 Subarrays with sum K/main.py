# Link: https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1


class Solution:
    def cntSubarrays(self, arr, k):
        prefixSums = {}
        res = 0
        currSum = 0

        for val in arr:
            currSum += val

            if currSum == k:
                res += 1

            if currSum - k in prefixSums:
                res += prefixSums[currSum - k]

            prefixSums[currSum] = prefixSums.get(currSum, 0) + 1

        return res


if __name__ == "__main__":
    sol = Solution()
    arr = [10, 2, -2, -20, 10]
    k = -10
    result = sol.cntSubarrays(arr, k)
    print(f"Number of subarrays with sum {k}: {result}")

    arr = [9, 4, 20, 3, 10, 5]
    k = 33
    result = sol.cntSubarrays(arr, k)
    print(f"Number of subarrays with sum {k}: {result}")

    arr = [1, 3, 5]
    k = 0
    result = sol.cntSubarrays(arr, k)
    print(f"Number of subarrays with sum {k}: {result}")

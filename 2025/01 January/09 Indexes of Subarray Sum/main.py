# Link: https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1


class Solution:
    def subarraySum(self, arr: list[int], target: int):
        getInd = {}
        ind = 1
        n = len(arr)
        sum = 0

        for i in range(n):
            sum += arr[i]
            if sum == target:
                return (1, ind)

            remain = sum - target

            if remain in getInd:
                return (getInd[remain] + 1, ind)

            getInd[sum] = ind
            ind += 1

        return (-1,)


if __name__ == "__main__":
    solution = Solution()

    arr = [1, 2, 3, 7, 5]
    target = 12
    result = solution.subarraySum(arr, target)
    print(" ".join(map(str, result)))

    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    target = 15
    result = solution.subarraySum(arr, target)
    print(" ".join(map(str, result)))

    arr = [5, 3, 4]
    target = 2
    result = solution.subarraySum(arr, target)
    print(" ".join(map(str, result)))

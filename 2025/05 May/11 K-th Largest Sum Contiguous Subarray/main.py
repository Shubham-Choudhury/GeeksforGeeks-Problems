# Link: https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1


class Solution:
    def kthLargest(self, arr, k):
        n = len(arr)

        subarraySums = []
        for i in range(n):
            total = 0
            for j in range(i, n):
                total += arr[j]
                subarraySums.append(total)

        subarraySums.sort(reverse=True)

        return subarraySums[k - 1]


if __name__ == "__main__":
    obj = Solution()
    arr = [3, 2, 1]
    k = 2
    print(obj.kthLargest(arr, k))

    arr = [2, 6, 4, 1]
    k = 3
    print(obj.kthLargest(arr, k))

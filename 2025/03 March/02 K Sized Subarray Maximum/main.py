# Link: https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1


class Solution:
    def maxOfSubarrays(self, arr, k):
        n = len(arr)
        if k == 1:
            return arr

        ans = []
        deque = []

        for i in range(n):
            if deque and deque[0] < i - k + 1:
                deque.pop(0)

            while deque and arr[deque[-1]] < arr[i]:
                deque.pop()

            deque.append(i)
            if i >= k - 1:
                ans.append(arr[deque[0]])

        return ans


# Driver Code
if __name__ == "__main__":
    obj = Solution()

    arr = [1, 2, 3, 1, 4, 5, 2, 3, 6]
    k = 3
    print(" ".join(map(str, obj.maxOfSubarrays(arr, k))))

    arr = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13]
    k = 4
    print(" ".join(map(str, obj.maxOfSubarrays(arr, k))))

    arr = [5, 1, 3, 4, 2, 6]
    k = 1
    print(" ".join(map(str, obj.maxOfSubarrays(arr, k))))

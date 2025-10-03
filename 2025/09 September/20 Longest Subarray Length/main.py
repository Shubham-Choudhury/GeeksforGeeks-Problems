# Link: https://www.geeksforgeeks.org/problems/longest-subarray-length--202010/1


class Solution:
    def longestSubarray(self, arr: list[int]) -> int:
        n = len(arr)

        nextGreater = [n] * n
        prevGreater = [-1] * n

        st = []

        for i in range(n):
            while st and arr[st[-1]] < arr[i]:
                nextGreater[st.pop()] = i
            st.append(i)

        st.clear()

        for i in range(n - 1, -1, -1):
            while st and arr[st[-1]] < arr[i]:
                prevGreater[st.pop()] = i
            st.append(i)

        maxLength = 0
        for i in range(n):
            windowSize = nextGreater[i] - prevGreater[i] - 1
            if windowSize >= arr[i]:
                maxLength = max(maxLength, windowSize)

        return maxLength


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 3]
    result = sol.longestSubarray(arr)
    print(f"Longest subarray length: {result}")

    arr = [6, 4, 2, 5]
    result = sol.longestSubarray(arr)
    print(f"Longest subarray length: {result}")

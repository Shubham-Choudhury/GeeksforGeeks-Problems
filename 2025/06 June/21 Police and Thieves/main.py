# Link: https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1


class Solution:
    def catchThieves(self, arr, k):
        n = len(arr)
        i, j = 0, 0
        count = 0

        while i < n and j < n:
            while i < n and arr[i] != "P":
                i += 1
            while j < n and arr[j] != "T":
                j += 1

            if i < n and j < n and abs(i - j) <= k:
                count += 1
                i += 1
                j += 1
            elif j < n and j < i:
                j += 1
            elif i < n and i < j:
                i += 1

        return count


if __name__ == "__main__":
    sol = Solution()
    arr = ["P", "T", "T", "P", "T"]
    k = 1
    result = sol.catchThieves(arr, k)
    print(f"Number of thieves caught: {result}")

    arr = ["T", "T", "P", "P", "T", "P"]
    k = 2
    result = sol.catchThieves(arr, k)
    print(f"Number of thieves caught: {result}")

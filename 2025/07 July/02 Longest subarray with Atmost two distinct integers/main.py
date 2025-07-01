# Link: https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1


class Solution:
    def totalElements(self, arr):
        mp = {}
        i = j = 0
        n = len(arr)
        size = 0

        while j < n:
            mp[arr[j]] = mp.get(arr[j], 0) + 1

            while len(mp) > 2:
                mp[arr[i]] -= 1

                if mp[arr[i]] == 0:
                    del mp[arr[i]]
                i += 1

            size = max(size, j - i + 1)
            j += 1

        return size


if __name__ == "__main__":
    sol = Solution()
    arr = [2, 1, 2]
    result = sol.totalElements(arr)
    print(
        f"The length of the longest subarray with at most two distinct integers is: {result}"
    )

    arr = [3, 1, 2, 2, 2, 2]
    result = sol.totalElements(arr)
    print(
        f"The length of the longest subarray with at most two distinct integers is: {result}"
    )

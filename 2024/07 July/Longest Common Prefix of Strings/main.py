# Link: https://geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1


class Solution:
    def longestCommonPrefix(self, arr):
        if not arr:
            return "-1"

        prefix = arr[0]

        for i in range(1, len(arr)):
            j = 0
            while j < len(prefix) and j < len(arr[i]) and prefix[j] == arr[i][j]:
                j += 1

            prefix = prefix[:j]

            if not prefix:
                return "-1"

        return prefix


if __name__ == "__main__":
    obj = Solution()
    arr = ["geeksforgeeks", "geeks", "geek", "geezer"]
    print(obj.longestCommonPrefix(arr))

    arr = ["hello", "world"]
    print(obj.longestCommonPrefix(arr))

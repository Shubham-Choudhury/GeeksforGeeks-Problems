# Link: https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1


class Solution:
    def longestConsecutive(self, arr):
        mp = {}
        ans = 0
        for num in arr:
            mp[num] = mp.get(num, 0) + 1
        for num in arr:
            if mp.get(num - 1, 0) == 0:
                x = num
                while mp.get(x, 0) != 0:
                    x += 1
                ans = max(ans, x - num)
        return ans


if __name__ == "__main__":
    object = Solution()
    arr = [2, 6, 1, 9, 4, 5, 3]
    print(object.longestConsecutive(arr))

    arr = [1, 9, 3, 10, 4, 20, 2]
    print(object.longestConsecutive(arr))

    arr = [15, 13, 12, 14, 11, 10, 9]
    print(object.longestConsecutive(arr))

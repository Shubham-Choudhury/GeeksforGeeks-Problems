# Link: https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1


class Solution:
    def getSingle(self, arr):
        freq = {}
        for num in arr:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        for num in freq:
            if freq[num] == 1:
                return num
        return -1


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 10, 1, 1]
    print(obj.getSingle(arr))

    arr = [3, 2, 1, 34, 34, 1, 2, 34, 2, 1]
    print(obj.getSingle(arr))

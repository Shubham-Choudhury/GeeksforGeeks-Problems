# Link: https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1

from collections import Counter


class Solution:
    def sortByFreq(self, arr):
        freq_map = Counter(arr)
        temp = [(count, num) for num, count in freq_map.items()]
        temp.sort(key=lambda x: (-x[0], x[1]))
        res = []
        for count, num in temp:
            res.extend([num] * count)
        return res


if __name__ == "__main__":
    obj = Solution()
    arr = [5, 5, 4, 6, 4]
    res = obj.sortByFreq(arr)
    print(" ".join(map(str, res)))

    arr = [9, 9, 9, 2, 5]
    res = obj.sortByFreq(arr)
    print(" ".join(map(str, res)))

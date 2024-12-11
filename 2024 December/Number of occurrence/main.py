# Link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1


class Solution:
    def countFreq(self, arr, target):
        c = 0
        for num in arr:
            if num == target:
                c += 1
        return c


if __name__ == "__main__":
    object = Solution()
    arr = [1, 1, 2, 2, 2, 2, 3]
    target = 2
    print(object.countFreq(arr, target))

    arr = [1, 1, 2, 2, 2, 2, 3]
    target = 4
    print(object.countFreq(arr, target))

    arr = [8, 9, 10, 12, 12, 12]
    target = 12
    print(object.countFreq(arr, target))

# Link: https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1


class Solution:
    def findSmallest(self, arr):
        t = 1
        for i in arr:
            if t < i:
                return t
            t += i
        return t


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3]
    print(obj.findSmallest(arr))

    arr = [3, 6, 9, 10, 20, 28]
    print(obj.findSmallest(arr))

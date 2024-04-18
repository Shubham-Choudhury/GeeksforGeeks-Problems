# Link: https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1


class Solution:
    def twoRepeated(self, arr, n):
        array = []
        visit = set()
        for i in range(len(arr)):
            if arr[i] not in visit:
                visit.add(arr[i])
            else:
                array.append(arr[i])
        return array


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 1, 3, 4, 3]
    n = len(arr)
    print(obj.twoRepeated(arr, n))
    arr = [1, 2, 2, 1]
    n = len(arr)
    print(obj.twoRepeated(arr, n))

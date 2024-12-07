# Link: https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1


class Solution:
    def mergeOverlap(self, arr):
        arr.sort()
        result = []
        for interval in arr:
            if not result or result[-1][1] < interval[0]:
                result.append(interval)
            else:
                result[-1][1] = max(result[-1][1], interval[1])
        return result


if __name__ == "__main__":
    object = Solution()
    arr = [[1, 3], [2, 4], [6, 8], [9, 10]]
    result = object.mergeOverlap(arr)
    for interval in result:
        print(interval[0], interval[1])
    print()

    arr = [[6, 8], [1, 9], [2, 4], [4, 7]]
    result = object.mergeOverlap(arr)
    for interval in result:
        print(interval[0], interval[1])
    print()

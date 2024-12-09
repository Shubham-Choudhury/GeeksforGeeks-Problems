# Link: https://www.geeksforgeeks.org/problems/non-overlapping-intervals/1


class Solution:
    def minRemoval(self, intervals):
        if not intervals:
            return 0
        count = 0
        intervals.sort()
        prevEnd = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] < prevEnd:
                count += 1
                prevEnd = min(prevEnd, intervals[i][1])
            else:
                prevEnd = intervals[i][1]
        return count


if __name__ == "__main__":
    object = Solution()
    intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]
    print(object.minRemoval(intervals))

    intervals = [[1, 3], [1, 3], [1, 3]]
    print(object.minRemoval(intervals))

    intervals = [[1, 2], [5, 10], [18, 35], [40, 45]]
    print(object.minRemoval(intervals))

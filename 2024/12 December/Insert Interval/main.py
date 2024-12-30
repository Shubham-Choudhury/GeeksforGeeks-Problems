# Link: https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1


class Solution:
    def insertInterval(self, intervals, newInterval):
        intervals.append(newInterval)
        intervals.sort()
        n = len(intervals)
        ans = []

        el = intervals[0]
        for i in range(1, n):
            if intervals[i][0] > el[1]:
                ans.append(el)
                el = intervals[i]
            else:
                el[1] = max(el[1], intervals[i][1])
        ans.append(el)
        return ans


if __name__ == "__main__":
    object = Solution()
    intervals = [[1, 3], [4, 5], [6, 7], [8, 10]]
    newInterval = [5, 6]
    result = object.insertInterval(intervals, newInterval)
    for i in range(len(result)):
        print(result[i][0], result[i][1])
    print()

    intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]]
    newInterval = [4, 9]
    result = object.insertInterval(intervals, newInterval)
    for i in range(len(result)):
        print(result[i][0], result[i][1])
    print()

# Link: https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1


class Solution:
    def insertInterval(self, intervals, newInterval):
        res = []
        i = 0
        n = len(intervals)

        while i < n and intervals[i][1] < newInterval[0]:
            res.append(intervals[i])
            i += 1

        while i < n and intervals[i][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1

        res.append(newInterval)

        while i < n:
            res.append(intervals[i])
            i += 1

        return res


if __name__ == "__main__":
    sol = Solution()
    intervals = [[1, 3], [4, 5], [6, 7], [8, 10]]
    newInterval = [5, 6]
    result = sol.insertInterval(intervals, newInterval)
    print(result)

    intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]]
    newInterval = [4, 9]
    result = sol.insertInterval(intervals, newInterval)
    print(result)

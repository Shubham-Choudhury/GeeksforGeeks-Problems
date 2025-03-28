# Link: https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1


class Solution:
    def activitySelection(self, start, finish):
        res = a = []
        for i in range(len(start)):
            a = [start[i], finish[i]]
            res.append(a)
            a = []
        res.sort(key=lambda x: x[1])
        cnt = 1
        j = res[0][1]
        for i in range(1, len(res)):
            if j < res[i][0]:
                cnt += 1
                j = res[i][1]
        return cnt


if __name__ == "__main__":
    obj = Solution()
    start = [1, 3, 0, 5, 8, 5]
    finish = [2, 4, 6, 7, 9, 9]
    result = obj.activitySelection(start, finish)
    print(result)

    start = [10, 12, 20]
    finish = [20, 25, 30]
    result = obj.activitySelection(start, finish)
    print(result)

# Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1


class Job:
    def __init__(self, profit=0, deadline=0):
        self.profit = profit
        self.deadline = deadline
        self.id = 0


class Solution:
    def JobScheduling(self, Jobs, n):
        ans = [0] * n
        abc = []
        for i in Jobs:
            abc.append([i.deadline, i.profit])
        abc.sort(key=lambda x: x[1], reverse=True)
        answer = 0
        for i in abc:
            b, c = i[0], i[1]
            while ans[b - 1] != 0 and b != 0:
                b -= 1
            if b != 0:
                answer += 1
                ans[b - 1] = c
        return [answer, sum(ans)]


if __name__ == "__main__":
    obj = Solution()
    arr1 = [Job(4, 20), Job(1, 10), Job(1, 40), Job(1, 30)]
    n = len(arr1)
    ans = obj.JobScheduling(arr1, n)
    print(ans[0], ans[1])

    arr2 = [Job(2, 100), Job(1, 19), Job(2, 27), Job(1, 25), Job(1, 15)]

    n = len(arr2)
    ans = obj.JobScheduling(arr2, n)
    print(ans[0], ans[1])

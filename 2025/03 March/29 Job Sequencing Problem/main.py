# Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1


class Solution:
    def find(self, parent, i):
        if parent[i] == i:
            return i
        parent[i] = self.find(parent, parent[i])
        return parent[i]

    def jobSequencing(self, deadline, profit):
        n = len(deadline)
        jobs = sorted(zip(profit, deadline), reverse=True)

        max_deadline = max(deadline)
        parent = [i for i in range(max_deadline + 1)]

        job_count, total_profit = 0, 0

        for p, d in jobs:
            available_slot = self.find(parent, min(d, max_deadline))

            if available_slot > 0:
                parent[available_slot] = self.find(parent, available_slot - 1)
                job_count += 1
                total_profit += p

        return [job_count, total_profit]


if __name__ == "__main__":
    obj = Solution()
    deadline = [2, 1, 2, 1, 3]
    profit = [100, 19, 27, 25, 15]
    result = obj.jobSequencing(deadline, profit)
    print("Number of jobs done:", result[0])
    print("Total profit:", result[1])

    deadline = [4, 1, 1, 1]
    profit = [20, 10, 40, 30]
    result = obj.jobSequencing(deadline, profit)
    print("Number of jobs done:", result[0])
    print("Total profit:", result[1])

    deadline = [3, 1, 2, 2]
    profit = [100, 19, 27, 25]
    result = obj.jobSequencing(deadline, profit)
    print("Number of jobs done:", result[0])
    print("Total profit:", result[1])

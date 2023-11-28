# Link: https://www.geeksforgeeks.org/problems/sum-of-dependencies-in-a-graph5311/1

# User function Template for python3


class Solution:
    def sumOfDependencies(self, adj, V):
        # code here
        cnt = 0
        for i in adj:
            cnt += len(i)
        return cnt


if __name__ == "__main__":
    obj = Solution()
    V = 4
    adj = [[1, 2], [2], [3], []]
    print(obj.sumOfDependencies(adj, V))

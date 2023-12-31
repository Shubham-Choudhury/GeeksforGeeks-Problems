# Link: https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

# User function Template for Python3

class Solution:
    def maxGold(self, n, m, M):
        for x in range(m):
            for y in range(n):
                if x>0:
                    m=M[y][x-1]
                    if y-1>=0:
                        m=max(m,M[y-1][x-1])
                    if y+1<n:
                        m=max(m,M[y+1][x-1])
                    M[y][x]+=m
        return max([r[-1] for r in M])


if __name__=="__main__":
    obj = Solution()
    M = [[1, 3, 3],
     [2, 1, 4],
     [0, 6, 4]]
    n, m = len(M), len(M[0])
    print(obj.maxGold(n, m, M))
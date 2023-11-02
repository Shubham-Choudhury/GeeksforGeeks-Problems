# Link: https://www.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/1

class Solution:
    def minDist(self, a, n, x, y):
        mini = float('inf')
        l = -1
        r = -1
        for i in range(n):
            if a[i] == x:
                l = i
            elif a[i] == y:
                r = i
            if l != -1 and r != -1:
                mini = min(mini, abs(l - r))
        if mini == float('inf'):
            return -1
        return mini
    
if __name__ == '__main__':
    a = [1,2,3,4]
    x = 1
    y = 4
    n = len(a)
    obj = Solution()
    print(obj.minDist(a, n, x, y))
# Link: https://www.geeksforgeeks.org/problems/reach-the-nth-point5433/1


class Solution:
    def nthPoint(self,n):
        # Code here
        a0, a1 = 0, 1
        for _ in range(n):
            a1, a0 = (a1+a0)%(10**9+7), a1
        return a1

if __name__=="__main__":
    obj=Solution()
    print(obj.nthPoint(4))
# Link: https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

class Solution:
    def findMaxSum(self,arr, n):
        # code here
        res=0
        pre=0
        cur=0
        for i in range(n):
            cur=pre+arr[i]
            pre=res
            res=max(cur,res)
        return res

if __name__=="__main__":
    obj = Solution()
    Arr = [5, 5, 10, 100, 10, 5]
    N = len(Arr)
    print(obj.findMaxSum(Arr,N))
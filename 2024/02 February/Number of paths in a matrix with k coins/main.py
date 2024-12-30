# Link: https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

class Solution:
    def numberOfPath (self, n, k, arr):
        dp=[]
        for i in range(n):
            c=[]
            for j in range(n):
                d=[]
                for k in range(k+1):
                    d.append(-1)
                c.append(d)
            dp.append(c)
        def trav(i,j,su):
            if(i>=n or j>=n or su>k):
                return 0
            if(dp[i][j][su]!=-1):
                return dp[i][j][su]
            if(i==n-1 and j==n-1 and k==su+arr[i][j]):
                return 1
            one=trav(i+1,j,su+arr[i][j])
            two=trav(i,j+1,su+arr[i][j])
            dp[i][j][su]=one+two
            return (dp[i][j][su])
        return trav(0,0,0)
    
if __name__=="__main__":
    obj=Solution()
    n=3
    k=12
    arr=[[1,2,3],[4,6,5],[3,2,1]]
    print(obj.numberOfPath(n,k,arr))
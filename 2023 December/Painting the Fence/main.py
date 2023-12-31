# Link: https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

class Solution:
    def countWays(self,n,k):
        # code here.
        if n==0:
            return 0
        if n==1:
            return k
        if n==2:
            return k*k
        
        dp = [0] * (n + 1)
        total = k
        mod = 1000000007
        
        dp[1] = k
        dp[2] = k * k   
         
        for i in range(3,n+1):
            dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod
             
        return dp[n]
    
if __name__ == '__main__':
    obj = Solution()
    N=3
    K=2
    print(obj.countWays(N,K))
    N=2
    K=4
    print(obj.countWays(N,K))
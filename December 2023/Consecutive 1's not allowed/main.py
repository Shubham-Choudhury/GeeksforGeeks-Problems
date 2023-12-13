# Link: https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1

#User function Template for python3
class Solution:
    def countStrings(self, n):
        dp = [0] * (n + 1)
        if n==1 or n==2:
            return n+1
        dp[1] = 2
        dp[2] = 3

        for i in range(3, n + 1):
            dp[i] = (dp[i - 1] + dp[i - 2]) % (10**9 + 7)

        return dp[n]

if __name__=="__main__":
    obj=Solution()
    N=3
    print(obj.countStrings(N))
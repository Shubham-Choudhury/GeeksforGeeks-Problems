# Link: https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

class Solution:
    def sumSubstrings(self,s):
        n = len(s)
        M = 10**9+7
        dp = [0]*(n+1)
        for i in range(n):
            dp[i+1] = (dp[i]*10+(i+1)*(ord(s[i])-ord('0')))%M
        return sum(dp)%M
    
if __name__=="__main__":
    obj = Solution()
    s = "1234"
    print(obj.sumSubstrings(s))
    s="421"
    print(obj.sumSubstrings(s))
    
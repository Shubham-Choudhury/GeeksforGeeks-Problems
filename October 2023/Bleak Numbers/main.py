# Link: https://practice.geeksforgeeks.org/problems/bleak-numbers1552/1

class Solution:
    def countSetBits(self, x):
        count = 0
        while(x):
            x=x&(x-1)
            count=count+1
        return count
        
    def ceilLog2(self,x) :
        count = 0
        x = x - 1
     
        while (x > 0) :
            x = x>>1
            count = count + 1
     
        return count
        
    def is_bleak(self, n):
		# Code here
        for x in range((n - self.ceilLog2(n)),n):
            if (x + self.countSetBits(x) == n) :
                return 0
        return 1
    
if __name__ == '__main__':
    obj = Solution()
    print(obj.is_bleak(4))
    print(obj.is_bleak(3))
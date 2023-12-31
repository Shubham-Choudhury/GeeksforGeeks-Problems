# Link: https://www.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1


class Solution:
    def posOfRightMostDiffBit(self,m,n):
        x=(m^n)
        count=0
        while x!=0:
            count+=1
            if x%2!=0:
                return count
            x=x//2
        return -1
    
if __name__ == '__main__':
    obj=Solution()
    print(obj.posOfRightMostDiffBit(11,9))
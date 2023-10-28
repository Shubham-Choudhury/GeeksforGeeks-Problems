# Link:

class Solution:
    def colName (self, n):
        ans=""
        while(n!=0):
            n-=1
            char=chr(n%26+ord('A'))
            ans=char+ans
            n//=26
            
        return ans
    
if __name__ == '__main__':
    obj = Solution()
    print(obj.colName(28))
    print(obj.colName(13))


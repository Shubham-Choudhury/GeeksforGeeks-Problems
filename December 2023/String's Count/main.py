# Link: https://www.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints1135/1

class Solution:
    def countStr(self, n):
        return ((n**3)+(3*n)+2)//2
    
if __name__ == '__main__':
    obj=Solution()
    N=1
    print(obj.countStr(N))
    N=3
    print(obj.countStr(N))
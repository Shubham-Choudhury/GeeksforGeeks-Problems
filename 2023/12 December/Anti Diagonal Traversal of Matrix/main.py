# Link: https://www.geeksforgeeks.org/problems/print-diagonally1623/1

class Solution:
    def antiDiagonalPattern(self,matrix):
        n=len(matrix)
        ans=[]
        if n==1: return [matrix[0][0]]
        for i in range(n):
            for j in range(0,i+1):
                ans.append(matrix[j][i-j])
        for i in range(1,n):
            k=i
            for j in range(n-1, i-1,-1):
                ans.append(matrix[k][j])
                k+=1
        return ans
    
if __name__ == '__main__':
    obj = Solution()
    matrix = [[1,2,3],[4,5,6],[7,8,9]]
    print(obj.antiDiagonalPattern(matrix))
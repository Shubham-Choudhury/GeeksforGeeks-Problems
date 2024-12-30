# Link: https://www.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1

class Solution:
    def sMat(self, matrix, n, i):
        mat = [[0] * (n-1) for _ in range(n-1)]
            
        for j in range(1, n):
            c = 0
            for k in range(n):
                if k != i:
                    mat[j-1][c] = matrix[j][k]
                    c += 1
        
        return mat
        
    def determinantOfMatrix(self, matrix, n):
        if n == 1:
            return matrix[0][0]
        
        res = 0
        for i in range(n):
            mat = self.sMat(matrix, n, i)
            if i % 2 == 0:
                res += matrix[0][i] * self.determinantOfMatrix(mat, n-1)
            else:
                res += -1 * matrix[0][i] * self.determinantOfMatrix(mat, n-1)
        
        return res
    
if __name__ == '__main__':
    obj=Solution()
    n=4
    matrix=[[1,0,2,-1],[3,0,0,5],[2,1,4,-3],[1,0,5,0]]
    print(obj.determinantOfMatrix(matrix,n))
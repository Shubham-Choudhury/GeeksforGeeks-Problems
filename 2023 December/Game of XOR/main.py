# Link: https://www.geeksforgeeks.org/problems/game-of-xor1541/1

class Solution:
    def gameOfXor(self, N , A):
        # code here
        ans = 0
        for i, e in enumerate(A):
            if (i+1)*(N-i)%2 == 0:
                ans ^= 0
            else:
                ans ^= e
        return ans
    
if __name__ == '__main__':
    obj = Solution()
    A=[1,2,3]
    print(obj.gameOfXor(len(A), A))
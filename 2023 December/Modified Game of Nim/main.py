# Link: https://www.geeksforgeeks.org/problems/variation-in-nim-game4317/1


class Solution:
    def findWinner(self, n, A):
        xor_result = 0
        for num in A:
            xor_result ^= num

        if xor_result == 0:
            return 1
        elif n % 2 == 0:
            return 1
        else:
            return 2
        
if __name__=="__main__":
    obj = Solution()
    print(obj.findWinner(4, [1, 1, 1, 1]))
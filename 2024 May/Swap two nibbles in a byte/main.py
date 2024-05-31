# Link: https://www.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1

class Solution:
    def swapNibbles (self, n):
        mask = (1 << 4) - 1
        return ((n&mask) << 4) | (n >> 4)


if __name__ == "__main__":
    obj = Solution()
    n=100
    print(obj.swapNibbles(n)) 
    n=129
    print(obj.swapNibbles(n)) 
# Link: https://www.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1


class Solution:
    def maxXor(self, arr):
        mask, out = 0, 0
        for i in range(32, -1, -1):
            mask = mask | 1 << i
            f = set([x & mask for x in arr])
            temp = out | 1 << i
            for j in f:
                if j ^ temp in f:
                    out = temp
        return out


if __name__ == "__main__":
    obj = Solution()
    arr = [25, 10, 2, 8, 5, 3]
    print(obj.maxXor(arr))
    arr = [1, 2, 3, 4, 5, 6, 7]
    print(obj.maxXor(arr))

# Link: https://www.geeksforgeeks.org/problems/reverse-bits3556/1


class Solution:
    def reversedBits(self, x):
        res = 0
        for i in range(31):
            res = res | (x & 1)
            res <<= 1
            x >>= 1

        return res


if __name__ == "__main__":
    obj = Solution()
    x = 1
    print(obj.reversedBits(x))
    x = 5
    print(obj.reversedBits(x))

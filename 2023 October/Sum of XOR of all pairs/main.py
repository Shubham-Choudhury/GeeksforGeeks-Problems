# Link: https://practice.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs0723/1


class Solution:
    def sumXOR(self, arr, n):
        sum = 0
        for i in range(32):
            unsetBits, setBits = 0, 0
            idSum = 0
            for a in arr:
                if ((1 << i) & a)!=0:
                    setBits += 1
                else:
                    unsetBits += 1

            idSum = setBits * unsetBits * (1 << i)
            sum += idSum

        return sum


if __name__ == "__main__":
    obj = Solution()
    arr = [7, 3, 5]
    n = len(arr)
    print(obj.sumXOR(arr, n))
    arr = [5, 9, 7, 6]
    n = len(arr)
    print(obj.sumXOR(arr, n))

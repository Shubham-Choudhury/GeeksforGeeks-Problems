# Link: https://www.geeksforgeeks.org/problems/sum-of-products5049/1


class Solution:
    def pairAndSum(self, n, arr):
        bit_counts, bit_and_sum = [0] * 32, 0
        for a in arr:
            for i in range(32):
                mask = 1 << i
                if a & mask:
                    bit_and_sum += bit_counts[i] * mask
                    bit_counts[i] += 1
                elif mask > a:
                    break
        return bit_and_sum


if __name__ == "__main__":
    obj = Solution()
    arr = [5, 10, 15]
    n = len(arr)
    print(obj.pairAndSum(n, arr))
    arr = [10, 20, 30, 40]
    n = len(arr)
    print(obj.pairAndSum(n, arr))

# Link: https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

class Solution:
    # Function to check if Kth bit is set or not.
    def checkKthBit(self, n, k):
        binary_str = format(int(n), "b")
        if len(binary_str) <= k:
            return False
        if binary_str[len(binary_str) - 1 - k] == "1":
            return True
        else:
            return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkKthBit(4, 0))
    print(obj.checkKthBit(4, 2))
    print(obj.checkKthBit(500, 3))
    print(obj.checkKthBit(5789, 25))


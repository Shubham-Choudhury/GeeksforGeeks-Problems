# Link: https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1


class Solution:
    def numberSequence(self, m, n):
        if m < n:
            return 0
        if n == 0:
            return 1
        return self.numberSequence(m - 1, n) + self.numberSequence(m // 2, n - 1)


if __name__ == "__main__":
    obj = Solution()
    m = 10
    n = 4
    print(obj.numberSequence(m, n))
    m = 5
    n = 2
    print(obj.numberSequence(m, n))

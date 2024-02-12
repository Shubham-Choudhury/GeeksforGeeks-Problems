# Link: https://www.geeksforgeeks.org/problems/recursive-sequence1611/1


class Solution:
    def sequence(self, n):
        MOD = 10**9 + 7
        result = 0
        term = 1
        for i in range(1, n + 1):
            product = 1
            for j in range(i):
                product = (product * term) % MOD
                term += 1
            result = (result + product) % MOD

        return result


if __name__ == "__main__":
    obj = Solution()
    print(obj.sequence(5))
    print(obj.sequence(7))

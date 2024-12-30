# Link: https://www.geeksforgeeks.org/problems/print-pattern3549/1

# User function Template for python3


class Solution:
    def pattern(self, N):
        temp = N
        if N <= 0:
            return [N]

        result = []
        while N > 0:
            result.append(N)
            N -= 5

        while N <= temp:
            result.append(N)
            N += 5

        return result


if __name__ == "__main__":
    N = 10
    ob = Solution()
    print(ob.pattern(N))

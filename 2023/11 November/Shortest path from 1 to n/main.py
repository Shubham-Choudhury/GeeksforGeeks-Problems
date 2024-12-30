# Link: https://www.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1

# User function Template for python3


class Solution:
    def minimumStep(self, n):
        # complete the function here
        res = -2
        while n:
            res += (n % 3) + 1
            n //= 3
        return res


if __name__ == "__main__":
    obj = Solution()
    n = 9
    print(obj.minimumStep(n))

    n = 4
    print(obj.minimumStep(n))

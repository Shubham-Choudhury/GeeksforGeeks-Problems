# Link: https://www.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1

from collections import deque

class Solution:
    def generateBinary(self, n):
        res = []
        q = deque()

        q.append("1")

        while n > 0:
            s1 = q.popleft()
            res.append(s1)

            s2 = s1

            q.append(s1 + "0")

            q.append(s2 + "1")

            n -= 1

        return res


if __name__ == "__main__":
    obj = Solution()
    n = 4
    result = obj.generateBinary(n)
    print(f"Binary numbers from 1 to {n}: {result}")

    n = 6
    result = obj.generateBinary(n)
    print(f"Binary numbers from 1 to {n}: {result}")

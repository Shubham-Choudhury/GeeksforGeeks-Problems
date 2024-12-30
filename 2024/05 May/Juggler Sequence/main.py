# Link: https://www.geeksforgeeks.org/problems/juggler-sequence3930/1


class Solution:
    def jugglerSequence(self, n):
        ans = []

        while n > 1:
            ans.append(n)
            if n % 2 == 0:
                n = int(n ** (1 / 2))
            else:
                n = int(n ** (3 / 2))
        ans.append(1)

        return ans


if __name__ == "__main__":
    obj = Solution()
    n = 9
    print(obj.jugglerSequence(n))
    n = 6
    print(obj.jugglerSequence(n))

# Link: https://www.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1


class Solution:
    def minSteps(self, d):
        t, p = 0, 0
        while p < d or (p - d) % 2 != 0:
            t += 1
            p += t
        return t


if __name__ == "__main__":
    obj = Solution()
    d = 2
    print(obj.minSteps(d))

    d = 10
    print(obj.minSteps(d))

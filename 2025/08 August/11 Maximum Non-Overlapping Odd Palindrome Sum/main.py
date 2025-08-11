# Link: https://www.geeksforgeeks.org/problems/maximum-non-overlapping-odd-palindrome-sum/1


class Solution:
    def manacherArray(self, s):
        ms = "@#" + "#".join(s) + "#$"
        n = len(ms)
        p = [0] * n
        l = r = 0

        for i in range(1, n - 1):
            mirror = l + r - i
            if 0 <= mirror < n:
                p[i] = max(0, min(r - i, p[mirror]))

            while (
                i + p[i] + 1 < n
                and i - p[i] - 1 >= 0
                and ms[i + 1 + p[i]] == ms[i - 1 - p[i]]
            ):
                p[i] += 1

            if i + p[i] > r:
                l = i - p[i]
                r = i + p[i]

        return p

    def getLongest(self, cen, odd, p):
        pos = 2 * cen + 2 + (0 if odd else 1)
        return p[pos]

    def maxSum(self, s):
        n = len(s)
        leftMark = [1] * n
        rightMark = [1] * n

        p = self.manacherArray(s)

        for i in range(n):
            val = self.getLongest(i, 1, p)
            li = i + val // 2
            if li < n:
                leftMark[li] = max(leftMark[li], val)

        for i in range(n - 2, -1, -1):
            leftMark[i] = max(leftMark[i], leftMark[i + 1] - 2)

        for i in range(1, n):
            leftMark[i] = max(leftMark[i], leftMark[i - 1])

        for i in range(n - 1, -1, -1):
            val = self.getLongest(i, 1, p)
            ri = i - val // 2
            if ri >= 0:
                rightMark[ri] = max(rightMark[ri], val)

        for i in range(1, n):
            rightMark[i] = max(rightMark[i], rightMark[i - 1] - 2)

        for i in range(n - 2, -1, -1):
            rightMark[i] = max(rightMark[i], rightMark[i + 1])

        ans = 0
        for i in range(n - 1):
            ans = max(ans, leftMark[i] + rightMark[i + 1])

        return ans


if __name__ == "__main__":
    sol = Solution()
    s = "gfgforgeeks"
    result = sol.maxSum(s)
    print(f"Maximum Non-Overlapping Odd Palindrome Sum: {result}")

    s = "xyabacbcz"
    result = sol.maxSum(s)
    print(f"Maximum Non-Overlapping Odd Palindrome Sum: {result}")

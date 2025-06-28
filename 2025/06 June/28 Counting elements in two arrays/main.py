# Link: https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1


class Solution:
    def countLessEq(self, a, b):
        n = len(a)
        m = len(b)

        res = [0] * n
        maxi = max(b)
        cnt = [0] * (maxi + 1)

        for i in range(m):
            cnt[b[i]] += 1

        for i in range(1, (maxi + 1)):
            cnt[i] += cnt[i - 1]

        for i in range(n):
            res[i] = cnt[min(a[i], maxi)]

        return res


if __name__ == "__main__":
    sol = Solution()
    a = [4, 8, 7, 5, 1]
    b = [4, 48, 3, 0, 1, 1, 5]
    result = sol.countLessEq(a, b)
    print(result)

    a = [10, 20]
    b = [30, 40, 50]
    result = sol.countLessEq(a, b)
    print(result)

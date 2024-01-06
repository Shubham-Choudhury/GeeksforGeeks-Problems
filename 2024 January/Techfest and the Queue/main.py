# Link: https://www.geeksforgeeks.org/problems/techfest-and-the-queue1044/1


class Solution:
    def sumOfPowers(self, a: int, b: int) -> int:
        spf = [i for i in range(b + 1)]
        for i in range(2, b + 1):
            if spf[i] == i:
                for j in range(i * i, b + 1, i):
                    if spf[j] == j:
                        spf[j] = i

        ans = 0
        for i in range(a, b + 1):
            cnt = 0
            while i > 1:
                cnt += 1
                i //= spf[i]

            ans += cnt

        return ans


if __name__ == "__main__":
    obj = Solution()
    a = 9
    b = 12
    print(obj.sumOfPowers(a, b))

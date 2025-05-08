# Link: https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1


class Solution:
    def findMax(self, s, k):
        if k == 0:
            return s

        n = len(s)
        ans = s

        for i in range(n - 1):
            for j in range(i + 1, n):
                if s[i] < s[j]:
                    s_list = list(s)
                    s_list[i], s_list[j] = s_list[j], s_list[i]
                    swapped = "".join(s_list)

                    candidate = self.findMax(swapped, k - 1)
                    if candidate > ans:
                        ans = candidate

        return ans

    def findMaximumNum(self, s, k):
        return self.findMax(s, k)


if __name__ == "__main__":

    sol = Solution()

    s = "1234567"
    k = 4
    result = sol.findMaximumNum(s, k)
    print(f"Largest number after {k} swaps: {result}")

    s = "3435335"
    k = 3
    result = sol.findMaximumNum(s, k)
    print(f"Largest number after {k} swaps: {result}")

    s = "1034"
    k = 2
    result = sol.findMaximumNum(s, k)
    print(f"Largest number after {k} swaps: {result}")

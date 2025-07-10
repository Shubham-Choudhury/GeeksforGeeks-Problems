# Link: https://www.geeksforgeeks.org/problems/trail-of-ones3242/1


class Solution:
    def countConsec(self, n: int) -> int:
        prev0, prev1 = 0, 0

        for i in range(n, 0, -1):
            curr0 = prev0 + prev1
            curr1 = prev0 + (1 << (n - i))
            prev0, prev1 = curr0, curr1

        return prev0


if __name__ == "__main__":
    sol = Solution()
    n = 2
    result = sol.countConsec(n)
    print(f"Number of ways to form a trail of ones for n = {n}: {result}")

    n = 3
    result = sol.countConsec(n)
    print(f"Number of ways to form a trail of ones for n = {n}: {result}")

    n = 5
    result = sol.countConsec(n)
    print(f"Number of ways to form a trail of ones for n = {n}: {result}")

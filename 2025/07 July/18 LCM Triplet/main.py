# Link: https://www.geeksforgeeks.org/problems/lcm-triplet1501/1


class Solution:
    def lcmTriplets(self, n):
        if n < 3:
            return n

        if n % 2 != 0:
            return n * (n - 1) * (n - 2)

        if n % 3 != 0:
            return n * (n - 1) * (n - 3)
        return (n - 1) * (n - 2) * (n - 3)


if __name__ == "__main__":
    sol = Solution()
    n = 9
    result = sol.lcmTriplets(n)
    print(f"The LCM of the triplet for n={n} is: {result}")

    n = 7
    result = sol.lcmTriplets(n)
    print(f"The LCM of the triplet for n={n} is: {result}")

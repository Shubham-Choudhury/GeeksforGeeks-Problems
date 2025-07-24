# Link: https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1


class Solution:
    def getLastMoment(self, n, left, right):
        max_left = max(left) if left else 0

        max_right = max(n - r for r in right) if right else 0

        return max(max_left, max_right)


if __name__ == "__main__":
    sol = Solution()
    n = 4
    left = [2]
    right = [0, 1, 3]
    result = sol.getLastMoment(n, left, right)
    print(f"Last moment before all ants fall out: {result}")

    n = 4
    left = []
    right = [0, 1, 2, 3, 4]
    result = sol.getLastMoment(n, left, right)
    print(f"Last moment before all ants fall out: {result}")

    n = 3
    left = [0]
    right = [3]
    result = sol.getLastMoment(n, left, right)
    print(f"Last moment before all ants fall out: {result}")

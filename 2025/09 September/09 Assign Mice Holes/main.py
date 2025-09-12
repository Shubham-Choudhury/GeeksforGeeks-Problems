# Link: https://www.geeksforgeeks.org/problems/assign-mice-holes3053/1


class Solution:
    def assignHole(self, mices, holes):
        mices.sort()
        holes.sort()
        n = len(mices)
        Max = 0
        for i in range(n):
            if Max < abs(mices[i] - holes[i]):
                Max = abs(mices[i] - holes[i])

        return Max


if __name__ == "__main__":
    sol = Solution()
    mices = [4, -4, 2]
    holes = [4, 0, 5]
    result = sol.assignHole(mices, holes)
    print("Minimum time to assign mice to holes:", result)

    mices = [1, 2]
    holes = [20, 10]
    result = sol.assignHole(mices, holes)
    print("Minimum time to assign mice to holes:", result)

# Link: https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1


class Solution:
    def kadane(self, temp):
        rows = len(temp)

        currSum = 0
        maxSum = float("-inf")

        for i in range(rows):
            currSum += temp[i]

            if maxSum < currSum:
                maxSum = currSum

            if currSum < 0:
                currSum = 0

        return maxSum

    def maxRectSum(self, mat):
        rows = len(mat)
        cols = len(mat[0])

        maxSum = float("-inf")

        temp = [0] * rows

        for left in range(cols):
            temp = [0] * rows

            for right in range(left, cols):
                for row in range(rows):
                    temp[row] += mat[row][right]

                sumValue = self.kadane(temp)

                maxSum = max(maxSum, sumValue)

        return maxSum


if __name__ == "__main__":
    sol = Solution()
    mat = [[1, 2, -1, -4, -20], [-8, -3, 4, 2, 1], [3, 8, 10, 1, 3], [-4, -1, 1, 7, -6]]
    result = sol.maxRectSum(mat)
    print(f"Maximum sum rectangle: {result}")

    mat = [[-1, -2], [-3, -4]]
    result = sol.maxRectSum(mat)
    print(f"Maximum sum rectangle: {result}")

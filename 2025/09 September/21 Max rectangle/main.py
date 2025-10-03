# Link: https://www.geeksforgeeks.org/problems/max-rectangle/1


class Solution:
    def getMaxArea(self, heights):
        n = len(heights)
        s = []
        res = 0

        for i in range(n):
            while s and heights[s[-1]] >= heights[i]:
                tp = s.pop()
                width = i if not s else i - s[-1] - 1

                res = max(res, heights[tp] * width)
            s.append(i)

        while s:
            tp = s.pop()
            width = n if not s else n - s[-1] - 1
            res = max(res, heights[tp] * width)

        return res

    def maxArea(self, mat):
        n, m = len(mat), len(mat[0])
        heights = [0] * m
        ans = 0

        for i in range(n):
            for j in range(m):
                if mat[i][j] == 1:
                    heights[j] += 1
                else:
                    heights[j] = 0
            ans = max(ans, self.getMaxArea(heights))

        return ans


if __name__ == "__main__":
    obj = Solution()
    matrix = [[0, 1, 1, 0], [1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 0, 0]]
    result = obj.maxArea(matrix)
    print(f"Maximum rectangle area is: {result}")

    matrix = [[0, 1, 1], [1, 1, 1], [0, 1, 1]]
    result = obj.maxArea(matrix)
    print(f"Maximum rectangle area is: {result}")

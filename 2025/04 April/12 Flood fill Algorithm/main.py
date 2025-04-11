# Link: https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1


class Solution:
    def bfs(self, sr, sc, image, ans, newcolor, initcolor):
        q = [[sr, sc]]
        ans[sr][sc] = newcolor
        row = len(image)
        col = len(image[0])
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while q:
            i, j = q.pop(0)
            for dr, dc in directions:
                nrow = i + dr
                ncol = j + dc
                if (
                    0 <= nrow < row
                    and 0 <= ncol < col
                    and image[nrow][ncol] == initcolor
                    and ans[nrow][ncol] != newcolor
                ):
                    q.append([nrow, ncol])
                    ans[nrow][ncol] = newcolor

    def floodFill(self, image, sr, sc, newcolor):
        initcolor = image[sr][sc]
        if initcolor == newcolor:
            return image
        ans = [row[:] for row in image]
        self.bfs(sr, sc, image, ans, newcolor, initcolor)
        return ans


if __name__ == "__main__":
    sol = Solution()
    image = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]]
    sr = 1
    sc = 2
    newColor = 2
    result = sol.floodFill(image, sr, sc, newColor)
    for row in result:
        print(row)
    print()

    image = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
    sr = 1
    sc = 1
    newColor = 2
    result = sol.floodFill(image, sr, sc, newColor)
    for row in result:
        print(row)
    print()

    image = [[0, 1, 0], [0, 1, 0]]
    sr = 0
    sc = 1
    newColor = 0
    result = sol.floodFill(image, sr, sc, newColor)
    for row in result:
        print(row)
    print()

# Link: https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1


class Solution:
    def spirallyTraverse(self, mat):
        ans = []
        top, left = 0, 0
        bottom, right = len(mat) - 1, len(mat[0]) - 1

        while top <= bottom and left <= right:
            i, j = top, left
            while j <= right:
                ans.append(mat[i][j])
                j += 1
            j -= 1
            i += 1

            while i <= bottom:
                ans.append(mat[i][j])
                i += 1

            top += 1
            right -= 1
            i, j = bottom, right

            if top > bottom or left > right:
                return ans

            while j >= left:
                ans.append(mat[i][j])
                j -= 1

            j = left
            i -= 1

            while i >= top:
                ans.append(mat[i][j])
                i -= 1

            left += 1
            bottom -= 1

        return ans


if __name__ == "__main__":
    object = Solution()
    mat = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
    ans = object.spirallyTraverse(mat)
    print(" ".join(map(str, ans)))

    mat = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]
    ans = object.spirallyTraverse(mat)
    print(" ".join(map(str, ans)))

    mat = [[32, 44, 27, 23], [54, 28, 50, 62]]
    ans = object.spirallyTraverse(mat)
    print(" ".join(map(str, ans)))

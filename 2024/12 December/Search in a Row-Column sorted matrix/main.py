# Link: https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1


class Solution:
    def matSearch(self, mat, x):
        n = len(mat)
        m = len(mat[0])
        l = 0
        h = m - 1
        while l < n and h >= 0:
            if mat[l][h] == x:
                return True
            elif mat[l][h] < x:
                l += 1
            else:
                h -= 1
        return False


if __name__ == "__main__":
    object = Solution()
    mat = [[3, 30, 38], [20, 52, 54], [35, 60, 69]]
    x = 62
    print(object.matSearch(mat, x))

    mat = [[18, 21, 27], [38, 55, 67]]
    x = 55
    print(object.matSearch(mat, x))

    mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    x = 3
    print(object.matSearch(mat, x))

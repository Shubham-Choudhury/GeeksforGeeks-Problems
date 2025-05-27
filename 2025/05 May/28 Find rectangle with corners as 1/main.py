# Link: https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1


class Solution:
    def ValidCorner(self, mat):
        rows = len(mat)
        if rows == 0:
            return False
        columns = len(mat[0])

        for i in range(rows):
            for p in range(i + 1, rows):
                count = 0

                for k in range(columns):
                    if mat[i][k] == 1 and mat[p][k] == 1:
                        count += 1
                if count >= 2:

                    return True
        return False


if __name__ == "__main__":
    obj = Solution()
    mat = [[1, 0, 0, 1, 0], [0, 0, 1, 0, 1], [0, 0, 0, 1, 0], [1, 0, 1, 0, 1]]
    result = obj.ValidCorner(mat)
    if result:
        print("Yes, rectangle with corners as 1 exists.")
    else:
        print("No, rectangle with corners as 1 does not exist.")

    mat = [[1, 1, 1, 1], [1, 0, 0, 1], [1, 0, 0, 1], [1, 1, 1, 1]]
    result = obj.ValidCorner(mat)
    if result:
        print("Yes, rectangle with corners as 1 exists.")
    else:
        print("No, rectangle with corners as 1 does not exist.")

    mat = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 1, 0, 1]]
    result = obj.ValidCorner(mat)
    if result:
        print("Yes, rectangle with corners as 1 exists.")
    else:
        print("No, rectangle with corners as 1 does not exist.")

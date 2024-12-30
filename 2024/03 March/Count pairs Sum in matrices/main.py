# Link: https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1


class Solution:
    def countPairs(self, mat1, mat2, n, x):
        sett = set()
        for i in range(n):
            for j in range(n):
                sett.add(mat1[i][j])

        count = 0
        for i in range(n):
            for j in range(n):
                if x - mat2[i][j] in sett:
                    count += 1
        return count


if __name__ == "__main__":
    obj = Solution()
    n = 3
    x = 21
    mat1 = [[1, 5, 6], [8, 10, 11], [15, 16, 18]]
    mat2 = [[2, 4, 7], [9, 10, 12], [13, 16, 20]]
    print(obj.countPairs(mat1, mat2, n, x))
    n = 2
    x = 10
    mat1 = [[1, 2], [3, 4]]
    mat2 = [[4, 5], [6, 7]]
    print(obj.countPairs(mat1, mat2, n, x))

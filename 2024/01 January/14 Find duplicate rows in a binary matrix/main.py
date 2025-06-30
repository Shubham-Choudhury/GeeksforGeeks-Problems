# Link: https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1


class Solution:
    def repeatedRows(self, arr, m, n):
        ans = []
        d = dict()
        for i in range(m):
            f = 0
            for key in d:
                if d[key] == arr[i]:
                    f = 1
                    break
            if f == 0:
                d[i] = arr[i]
            else:
                ans += (i,)
        return ans


if __name__ == "__main__":
    obj = Solution()
    R = 2
    C = 2
    matrix = [[1, 0], [1, 0]]
    print(obj.repeatedRows(matrix, R, C))
    R = 4
    C = 3
    matrix = [[1, 0, 0], [1, 0, 0], [0, 0, 0], [0, 0, 0]]
    print(obj.repeatedRows(matrix, R, C))

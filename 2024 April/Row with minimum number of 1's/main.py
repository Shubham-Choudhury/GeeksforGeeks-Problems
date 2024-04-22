# Link: https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1


class Solution:
    def minRow(self, n, m, a):
        result = 0
        max_limit = 9999999
        for i in range(n):
            count = 0
            for j in range(m):
                if a[i][j] == 1:
                    count += 1
            if count < max_limit:
                max_limit = count
                result = i
        return result + 1


if __name__ == "__main__":
    obj = Solution()
    n = 4
    m = 4
    a = [[1, 1, 1, 1], [1, 1, 0, 0], [0, 0, 1, 1], [1, 1, 1, 1]]
    print(obj.minRow(n, m, a))

    n = 3
    m = 3
    a = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    print(obj.minRow(n, m, a))

# Link: https://www.geeksforgeeks.org/problems/c-letters-collection4552/1


class Solution:
    def matrixSum(self, n, m, mat, q, queries):
        answer = []
        for k in range(q):
            hop = queries[k][0]
            i = queries[k][1]
            j = queries[k][2]
            sum = 0
            for ele in range(j - hop, j + hop + 1):
                if i - hop >= 0 and ele >= 0 and ele <= m - 1:
                    sum += mat[i - hop][ele]
                if i + hop <= n - 1 and ele >= 0 and ele <= m - 1:
                    sum += mat[i + hop][ele]
            for ele in range(i - hop + 1, i + hop):
                if j - hop >= 0 and ele >= 0 and ele <= n - 1:
                    sum += mat[ele][j - hop]
                if j + hop <= m - 1 and ele >= 0 and ele <= n - 1:
                    sum += mat[ele][j + hop]
            answer.append(sum)
        return answer


if __name__ == "__main__":
    m, n = 5, 4
    mat = [[1, 2, 3, 4, 10], [5, 6, 7, 8, 10], [9, 1, 3, 4, 10], [1, 2, 3, 4, 10]]
    q = 2
    queries = [[1, 0, 1], [2, 0, 1]]
    obj = Solution()
    print(obj.matrixSum(n, m, mat, q, queries))

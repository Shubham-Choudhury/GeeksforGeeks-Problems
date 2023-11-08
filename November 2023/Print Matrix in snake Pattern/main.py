# Link: https://www.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1


class Solution:
    # Function to return list of integers visited in snake pattern in matrix.
    def snakePattern(self, matrix):
        flag = 0
        ans = []
        for i in matrix:
            if flag % 2 == 0:
                ans.extend(i)
            else:
                i.reverse()
                ans.extend(i)
            flag += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    matrix = [[45, 48, 54], [21, 89, 87], [70, 78, 15]]
    ans = obj.snakePattern(matrix)
    print(ans)

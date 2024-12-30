# Link: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1


class Solution:
    def rowWithMax1s(self, arr):
        n = len(arr)
        m = len(arr[0]) if n > 0 else 0

        max_row_index = -1
        j = m - 1

        for i in range(n):
            while j >= 0 and arr[i][j] == 1:
                j -= 1
                max_row_index = i

        return max_row_index


if __name__ == "__main__":
    obj = Solution()
    arr = [[0, 1, 1, 1], [0, 0, 1, 1], [1, 1, 1, 1], [0, 0, 0, 0]]
    print(obj.rowWithMax1s(arr))

    arr = [[0, 0], [1, 1]]
    print(obj.rowWithMax1s(arr))

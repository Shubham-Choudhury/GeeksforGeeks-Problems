# Link: https://www.geeksforgeeks.org/problems/predict-the-column/1


class Solution:
    def columnWithMaxZeros(self, arr, N):
        idx = -1
        prvCount = 0
        for i in range(N):
            count = 0
            for j in range(N):
                if arr[j][i] == 0:
                    count += 1
            if count > prvCount:
                prvCount = count
                idx = i
        return idx


if __name__ == "__main__":
    obj = Solution()
    arr = [[1, 1, 0], [1, 0, 0], [1, 1, 1]]
    N = 3
    print(obj.columnWithMaxZeros(arr, N))

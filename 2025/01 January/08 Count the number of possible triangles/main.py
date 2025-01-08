# Link: https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1


class Solution:
    def countTriangles(self, arr: list[int]) -> int:
        n = len(arr)
        if n < 3:
            return 0

        arr.sort()
        triangleCount = 0
        for k in range(n - 1, 1, -1):
            i, j = 0, k - 1
            while i < j:
                if arr[i] + arr[j] > arr[k]:
                    triangleCount += j - i
                    j -= 1
                else:
                    i += 1
        return triangleCount


if __name__ == "__main__":
    solution = Solution()
    arr = [4, 6, 3, 7]
    print(solution.countTriangles(arr))

    arr = [10, 21, 22, 100, 101, 200, 300]
    print(solution.countTriangles(arr))

    arr = [1, 2, 3]
    print(solution.countTriangles(arr))

# Link: https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1


class Solution:
    def countTriangles(self, arr):
        res = 0
        arr.sort()

        for i in range(2, len(arr)):
            left, right = 0, i - 1

            while left < right:
                if arr[left] + arr[right] > arr[i]:
                    res += right - left
                    right -= 1

                else:
                    left += 1

        return res


if __name__ == "__main__":
    sol = Solution()
    arr = [4, 6, 3, 7]
    result = sol.countTriangles(arr)
    print(f"Number of possible triangles: {result}")

    arr = [10, 21, 22, 100, 101, 200, 300]
    result = sol.countTriangles(arr)
    print(f"Number of possible triangles: {result}")

    arr = [1, 2, 3]
    result = sol.countTriangles(arr)
    print(f"Number of possible triangles: {result}")

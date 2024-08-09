# Link: https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1


class Solution:
    def Maximize(self, arr):
        n = len(arr)
        arr.sort()

        val = 1000000007
        result = 0

        for i in range(n):
            result = (result + arr[i] * i) % val

        return result


if __name__ == "__main__":
    obj = Solution()
    arr = [5, 3, 2, 4, 1]
    print(obj.Maximize(arr))

    arr = [1, 2, 3]
    print(obj.Maximize(arr))

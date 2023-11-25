# Link: https://www.geeksforgeeks.org/problems/shuffle-integers2401/1


class Solution:
    def shuffleArray(self, arr, n):
        v = []
        i = 0
        mid = n // 2
        while i < n // 2 and mid < n:
            v.append(arr[i])
            v.append(arr[mid])
            i += 1
            mid += 1
        for i in range(n):
            arr[i] = v[i]


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 9, 15]
    n = len(arr)
    obj.shuffleArray(arr, n)
    for i in range(n):
        print(arr[i], end=" ")
    print()

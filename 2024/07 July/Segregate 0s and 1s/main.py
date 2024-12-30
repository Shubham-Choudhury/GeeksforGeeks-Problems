# Link: https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1


class Solution:
    def segregate0and1(self, arr):
        i = 0
        j = len(arr) - 1
        while i < j:
            if arr[i] == 1:
                arr[i], arr[j] = arr[j], arr[i]
                j -= 1
            else:
                i += 1


if __name__ == "__main__":
    obj = Solution()
    arr = [0, 0, 1, 1, 0]
    obj.segregate0and1(arr)
    print(" ".join(map(str, arr)))

    arr = [1, 1, 1, 1]
    obj.segregate0and1(arr)
    print(" ".join(map(str, arr)))

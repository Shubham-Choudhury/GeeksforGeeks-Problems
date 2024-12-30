# Link: https://www.geeksforgeeks.org/problems/reorganize-the-array4810/1


class Solution:
    def rearrange(self, arr):
        ans = [-1] * (len(arr) + 1)
        for elm in arr:
            if elm >= 0:
                ans[elm] = 1

        result = []
        for i in range(len(arr)):
            if ans[i] == 1:
                result.append(i)
            else:
                result.append(-1)

        return result


if __name__ == "__main__":
    obj = Solution()
    arr = [-1, -1, 6, 1, 9, 3, 2, -1, 4, -1]
    ans = obj.rearrange(arr)
    print(" ".join(map(str, ans)))

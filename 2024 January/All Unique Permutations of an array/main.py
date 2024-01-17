# Link: https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1


class Solution:
    def permutations(self, i, n, arr, ans):
        if i == n - 1:
            ans.add(tuple(arr))
            return
        for j in range(i, n):
            arr[i], arr[j] = arr[j], arr[i]
            self.permutations(i + 1, n, arr, ans)
            arr[i], arr[j] = arr[j], arr[i]

    def uniquePerms(self, arr, n):
        ans = set()
        self.permutations(0, n, arr, ans)
        ans = list(ans)
        ans.sort()
        return ans


if __name__ == "__main__":
    obj = Solution()
    n = 3
    arr = [1, 2, 1]
    print(obj.uniquePerms(arr, n))
    n = 2
    arr = [4, 5]
    print(obj.uniquePerms(arr, n))

# Link: https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1


class Solution:

    def CombinationSum2(self, arr, n, k):
        res = []
        arr.sort()

        def dfs(idx, sumi, path, res):
            if sumi == k:
                res.append(path)
            if sumi > k:
                return
            for i in range(idx, len(arr)):
                if i > idx and arr[i] == arr[i - 1]:
                    continue
                dfs(i + 1, sumi + arr[i], path + [arr[i]], res)

        dfs(0, 0, [], res)
        return res


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 3, 5]
    n = len(arr)
    k = 7
    print(obj.CombinationSum2(arr, n, k))

    arr = [5, 10, 15, 20, 25, 30]
    n = len(arr)
    k = 30
    print(obj.CombinationSum2(arr, n, k))

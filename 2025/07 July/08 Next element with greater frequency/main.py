# Link: https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1


class Solution:
    def findGreater(self, arr):
        n = len(arr)
        freq = {}

        for num in arr:
            freq[num] = freq.get(num, 0) + 1

        res = [-1] * n
        s = []

        for i in range(n):
            while s and freq[arr[i]] > freq[arr[s[-1]]]:
                res[s.pop()] = arr[i]
            s.append(i)

        return res


if __name__ == "__main__":
    sol = Solution()
    arr = [2, 1, 1, 3, 2, 1]
    result = sol.findGreater(arr)
    print(result)

    arr = [5, 1, 5, 6, 6]
    result = sol.findGreater(arr)
    print(result)

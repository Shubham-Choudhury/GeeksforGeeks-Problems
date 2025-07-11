# Link: https://www.geeksforgeeks.org/problems/next-greater-element/1


class Solution:
    def nextLargerElement(self, arr):
        n = len(arr)
        res = [-1] * n
        stk = []

        for i in range(2 * n - 1, -1, -1):
            while stk and stk[-1] <= arr[i % n]:
                stk.pop()

            if i < n and stk:
                res[i] = stk[-1]

            stk.append(arr[i % n])

        return res


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 3, 2, 4]
    result = sol.nextLargerElement(arr)
    print("Next Greater Elements:", result)

    arr = [0, 2, 3, 1, 1]
    result = sol.nextLargerElement(arr)
    print("Next Greater Elements:", result)

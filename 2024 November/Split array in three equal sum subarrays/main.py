# Link: https://www.geeksforgeeks.org/problems/split-array-in-three-equal-sum-subarrays/1


class Solution:
    def findSplit(self, arr):
        total_sum = sum(arr)
        if total_sum % 3 != 0:
            return [-1, -1]

        part = total_sum // 3
        n = len(arr)
        current_sum = 0
        count = 0
        indices = []

        for i in range(n):
            current_sum += arr[i]
            if current_sum == part and count < 2:
                indices.append(i)
                count += 1
                current_sum = 0

        if current_sum != part or count != 2:
            return [-1, -1]

        return indices


if __name__ == "__main__":
    solution = Solution()

    arr = [1, 3, 4, 0, 4]
    ans = solution.findSplit(arr)
    print("true" if ans[0] != -1 and ans[1] != -1 else "false")

    arr = [2, 3, 4]
    ans = solution.findSplit(arr)
    print("true" if ans[0] != -1 and ans[1] != -1 else "false")

    arr = [0, 1, 1]
    ans = solution.findSplit(arr)
    print("true" if ans[0] != -1 and ans[1] != -1 else "false")

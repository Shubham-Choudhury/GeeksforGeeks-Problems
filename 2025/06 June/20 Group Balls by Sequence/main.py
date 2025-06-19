# Link: https://www.geeksforgeeks.org/problems/group-balls-by-sequence/1


class Solution:
    def validgroup(self, arr, k):
        arr.sort()

        for i in range(len(arr)):
            if arr[i] == -1:
                continue

            count = 0
            curr = arr[i]

            for j in range(i, len(arr)):
                if arr[j] == curr:
                    count += 1
                    curr += 1
                    arr[j] = -1
                if count == k:
                    break

            if count != k:
                return False

        return True


if __name__ == "__main__":
    sol = Solution()
    arr = [10, 1, 2, 11]
    k = 3
    result = sol.validgroup(arr, k)
    print(result)

    arr = [10, 1, 2, 11]
    k = 2
    result = sol.validgroup(arr, k)
    print(result)

    arr = [7, 8, 9, 10, 11]
    k = 2
    result = sol.validgroup(arr, k)
    print(result)

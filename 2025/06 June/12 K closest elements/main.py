# Link: https://www.geeksforgeeks.org/problems/k-closest-elements3619/1


class Solution:
    def printKClosest(self, arr, k, x):
        n = len(arr)
        low, high, pos = 0, n - 1, -1

        while low <= high:
            mid = (low + high) // 2
            if arr[mid] < x:
                pos = mid
                low = mid + 1
            else:
                high = mid - 1

        left, right = pos, pos + 1

        if right < n and arr[right] == x:
            right += 1

        res = []

        while left >= 0 and right < n and len(res) < k:
            leftDiff = abs(arr[left] - x)
            rightDiff = abs(arr[right] - x)

            if leftDiff < rightDiff:
                res.append(arr[left])
                left -= 1
            else:
                res.append(arr[right])
                right += 1

        while left >= 0 and len(res) < k:
            res.append(arr[left])
            left -= 1

        while right < n and len(res) < k:
            res.append(arr[right])
            right += 1

        return res


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 3, 4, 10, 12]
    k = 2
    x = 4
    result = sol.printKClosest(arr, k, x)
    print(result)

    arr = [12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56]
    k = 4
    x = 35
    result = sol.printKClosest(arr, k, x)
    print(result)

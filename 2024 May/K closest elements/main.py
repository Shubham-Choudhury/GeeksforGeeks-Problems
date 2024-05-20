# Link: https://www.geeksforgeeks.org/problems/k-closest-elements3619/1


class Solution:
    def printKClosest(self, arr, n, k, x):
        def findCrossOver(arr, low, high, x):
            if arr[high] <= x:
                return high
            if arr[low] > x:
                return low
            mid = (low + high) // 2
            if arr[mid] <= x and arr[mid + 1] > x:
                return mid
            elif arr[mid] < x:
                return findCrossOver(arr, mid + 1, high, x)
            return findCrossOver(arr, low, mid - 1, x)

        l = findCrossOver(arr, 0, n - 1, x)
        r = l + 1
        count = 0

        if arr[l] == x:
            l -= 1

        closest = []

        while l >= 0 and r < n and count < k:
            if x - arr[l] < arr[r] - x:
                closest.append(arr[l])
                l -= 1
            else:
                closest.append(arr[r])
                r += 1
            count += 1

        while count < k and l >= 0:
            closest.append(arr[l])
            l -= 1
            count += 1

        while count < k and r < n:
            closest.append(arr[r])
            r += 1
            count += 1
        return closest


if __name__ == "__main__":
    obj = Solution()
    arr = [12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56]
    n = len(arr)
    k = 4
    x = 35
    print(obj.printKClosest(arr, n, k, x))

    arr = [1, 2, 3, 6, 10]
    n = len(arr)
    k = 3
    x = 4
    print(obj.printKClosest(arr, n, k, x))

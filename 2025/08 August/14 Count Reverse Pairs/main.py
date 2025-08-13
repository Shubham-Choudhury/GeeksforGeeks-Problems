# Link: https://www.geeksforgeeks.org/problems/count-reverse-pairs/1


class Solution:
    def merging(self, arr, low, mid, high):
        count = 0
        j = mid + 1

        for i in range(low, mid + 1):
            while j <= high and arr[i] > 2 * arr[j]:
                j += 1
            count += j - (mid + 1)

        temp = []
        left, right = low, mid + 1

        while left <= mid and right <= high:
            if arr[left] <= arr[right]:
                temp.append(arr[left])
                left += 1
            else:
                temp.append(arr[right])
                right += 1

        while left <= mid:
            temp.append(arr[left])
            left += 1

        while right <= high:
            temp.append(arr[right])
            right += 1

        for i in range(low, high + 1):
            arr[i] = temp[i - low]

        return count

    def mergeSort(self, arr, low, high):

        if low >= high:
            return 0

        mid = low + (high - low) // 2
        count = (
            self.mergeSort(arr, low, mid)
            + self.mergeSort(arr, mid + 1, high)
            + self.merging(arr, low, mid, high)
        )

        return count

    def countRevPairs(self, arr):
        return self.mergeSort(arr, 0, len(arr) - 1)


if __name__ == "__main__":
    sol = Solution()
    arr = [3, 2, 4, 5, 1, 20]
    result = sol.countRevPairs(arr)
    print(f"Count of reverse pairs: {result}")

    arr = [5, 4, 3, 2, 2]
    result = sol.countRevPairs(arr)
    print(f"Count of reverse pairs: {result}")

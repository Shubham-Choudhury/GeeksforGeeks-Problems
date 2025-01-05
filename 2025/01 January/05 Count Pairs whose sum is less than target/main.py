# Link: https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-less-than-target/1


class Solution:
    def countPairs(self, arr, target):
        arr.sort()
        n = len(arr)
        i, j, count = 0, n - 1, 0
        while i < j:
            sum_ = arr[i] + arr[j]
            if sum_ >= target:
                j -= 1
            else:
                count += j - i
                i += 1
        return count


if __name__ == "__main__":
    object = Solution()
    arr = [7, 2, 5, 3]
    target = 8
    print(object.countPairs(arr, target))

    arr = [5, 2, 3, 2, 4, 1]
    target = 5
    print(object.countPairs(arr, target))

    arr = [2, 1, 8, 3, 4, 7, 6, 5]
    target = 7
    print(object.countPairs(arr, target))

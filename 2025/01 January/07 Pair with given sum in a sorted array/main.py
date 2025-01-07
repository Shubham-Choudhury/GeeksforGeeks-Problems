# Link: https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1


class Solution:
    def countPairs(self, arr, target):
        n = len(arr)
        ans = 0
        i, j = 0, n - 1
        while i < j:
            if arr[i] + arr[j] == target:
                ele1 = arr[i]
                c1 = 0
                ele2 = arr[j]
                c2 = 0
                while i <= j and arr[i] == ele1:
                    c1 += 1
                    i += 1
                while i <= j and arr[j] == ele2:
                    c2 += 1
                    j -= 1
                if ele1 == ele2:
                    ans += (c1 * (c1 - 1)) // 2
                else:
                    ans += c1 * c2
            elif arr[i] + arr[j] < target:
                i += 1
            else:
                j -= 1
        return ans


if __name__ == "__main__":
    object = Solution()
    arr = [-1, 1, 5, 5, 7]
    target = 6
    print(object.countPairs(arr, target))

    arr = [1, 1, 1, 1]
    target = 2
    print(object.countPairs(arr, target))

    arr = [-1, 10, 10, 12, 15]
    target = 125
    print(object.countPairs(arr, target))

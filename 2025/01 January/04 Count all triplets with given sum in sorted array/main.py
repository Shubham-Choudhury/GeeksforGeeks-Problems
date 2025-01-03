# Link: https://www.geeksforgeeks.org/problems/count-all-triplets-with-given-sum-in-sorted-array/1


class Solution:
    def countTriplets(self, arr, target):
        c = 0
        for i in range(len(arr) - 2):
            l, r = i + 1, len(arr) - 1
            while l < r:
                sum_ = arr[i] + arr[l] + arr[r]
                if sum_ == target:
                    el1, el2 = arr[l], arr[r]
                    c1, c2 = 0, 0
                    while l <= r and arr[l] == el1:
                        l += 1
                        c1 += 1
                    while l <= r and arr[r] == el2:
                        r -= 1
                        c2 += 1
                    if el1 == el2:
                        c += (c1 * (c1 - 1)) // 2
                    else:
                        c += c1 * c2
                elif sum_ < target:
                    l += 1
                else:
                    r -= 1
        return c


if __name__ == "__main__":
    object = Solution()
    arr = [-3, -1, -1, 0, 1, 2]
    target = -2
    print(object.countTriplets(arr, target))

    arr = [-2, 0, 1, 1, 5]
    target = 1
    print(object.countTriplets(arr, target))

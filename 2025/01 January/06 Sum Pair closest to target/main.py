# Link: https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1


class Solution:
    def sumClosest(self, arr, target):
        ans = []
        arr.sort()
        n = len(arr)
        s = 0
        e = n - 1
        diff = float("inf")
        while s < e:
            pairsum = arr[s] + arr[e]
            if abs(pairsum - target) < diff:
                diff = min(abs(pairsum - target), diff)
                ans = [arr[s], arr[e]]
            if pairsum < target:
                s += 1
            elif pairsum > target:
                e -= 1
            else:
                return ans
        return ans


if __name__ == "__main__":
    object = Solution()
    arr = [10, 30, 20, 5]
    target = 25
    result = object.sumClosest(arr, target)
    if len(result) == 2:
        print(result[0], result[1])
    else:
        print("No pair found")

    arr = [5, 2, 7, 1, 4]
    target = 10
    result = object.sumClosest(arr, target)
    if len(result) == 2:
        print(result[0], result[1])
    else:
        print("No pair found")

    arr = [10]
    target = 10
    result = object.sumClosest(arr, target)
    if len(result) == 2:
        print(result[0], result[1])
    else:
        print("No pair found")

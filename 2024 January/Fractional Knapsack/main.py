# Link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1


class Item:
    def __init__(self, val, w):
        self.value = val
        self.weight = w


class Solution:
    def fractionalknapsack(self, W, arr, n):
        arr.sort(key=lambda x: x.value / x.weight, reverse=True)
        ans = 0
        for i in arr:
            if i.weight >= W:
                ans += W / i.weight * i.value
                return ans
            else:
                ans += i.value
                W -= i.weight
        return ans


if __name__ == "__main__":
    obj = Solution()
    W = 50
    arr = [Item(60, 10), Item(100, 20), Item(120, 30)]
    print(obj.fractionalknapsack(W, arr, len(arr)))
    W = 50
    arr = [Item(60, 10), Item(100, 20)]
    print(obj.fractionalknapsack(W, arr, len(arr)))

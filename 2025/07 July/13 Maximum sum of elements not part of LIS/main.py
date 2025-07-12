# Link: https://www.geeksforgeeks.org/problems/maximum-sum-of-elements-not-part-of-lis/1


class Solution:
    def __init__(self):
        self.mp = {}

    def insert(self, val):
        keys = sorted(self.mp.keys())
        len_val = 1
        sum_val = val

        for k in keys:
            if k >= val:
                break
            if self.mp[k][0] + 1 > len_val:
                len_val = self.mp[k][0] + 1
                sum_val = self.mp[k][1] + val

        toerase = []
        for k in keys:
            if k > val and self.mp[k][0] <= len_val:
                toerase.append(k)

        for k in toerase:
            del self.mp[k]

        self.mp[val] = [len_val, sum_val]

    def nonLisMaxSum(self, arr):
        self.mp.clear()
        for num in arr:
            self.insert(num)
        total_sum = sum(arr)
        lis_sum = max([v[1] for v in self.mp.values()], default=0)
        return total_sum - lis_sum


if __name__ == "__main__":
    sol = Solution()
    arr = [4, 6, 1, 2, 3, 8]
    result = sol.nonLisMaxSum(arr)
    print(f"Maximum sum of elements not part of LIS is {result}")

    arr = [5, 4, 3, 2, 1]
    result = sol.nonLisMaxSum(arr)
    print(f"Maximum sum of elements not part of LIS is {result}")

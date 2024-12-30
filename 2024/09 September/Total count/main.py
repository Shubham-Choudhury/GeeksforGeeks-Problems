# Link: https://www.geeksforgeeks.org/problems/total-count2415/1


class Solution:
    def totalCount(self, k, arr):
        total_sum = 0
        for i in arr:
            div = i // k
            total_sum += div
            rem = i % k
            if rem != 0:
                total_sum += 1
        return total_sum


if __name__ == "__main__":
    obj = Solution()
    k = 3
    arr = [5, 8, 10, 13]
    print(obj.totalCount(k, arr))

    k = 4
    arr = [10, 2, 3, 4, 7]
    print(obj.totalCount(k, arr))

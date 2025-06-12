# Link: https://www.geeksforgeeks.org/problems/koko-eating-bananas/1


class Solution:
    def check(self, arr, mid, k):
        hours = 0
        for bananas in arr:
            hours += bananas // mid
            if bananas % mid != 0:
                hours += 1
        return hours <= k

    def kokoEat(self, arr, k):
        lo = 1
        hi = max(arr)
        res = hi

        while lo <= hi:
            mid = lo + (hi - lo) // 2

            if self.check(arr, mid, k):
                res = mid
                hi = mid - 1
            else:
                lo = mid + 1

        return res


if __name__ == "__main__":
    sol = Solution()
    arr = [3, 6, 7, 11]
    k = 8
    print(sol.kokoEat(arr, k))

    arr = [30, 11, 23, 4, 20]
    k = 5
    print(sol.kokoEat(arr, k))

    arr = [5, 10, 15, 20]
    k = 7
    print(sol.kokoEat(arr, k))

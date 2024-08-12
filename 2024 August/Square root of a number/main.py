# Link: https://www.geeksforgeeks.org/problems/square-root/1


class Solution:
    def floorSqrt(self, n):
        ans = 0
        l, h = 0, n
        while l <= h:
            mid = (l + h) // 2
            if mid * mid == n:
                return mid
            elif mid * mid < n:
                ans = mid
                l = mid + 1
            else:
                h = mid - 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    n = 5
    print(obj.floorSqrt(n))
    n = 4
    print(obj.floorSqrt(n))

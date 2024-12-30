# Link: https://www.geeksforgeeks.org/problems/aggressive-cows/1


class Solution:
    def can_we_place(self, stalls, k, min_dist):
        cows_cnt = 1
        last = stalls[0]
        for i in range(1, len(stalls)):
            if stalls[i] - last >= min_dist:
                cows_cnt += 1
                last = stalls[i]
            if cows_cnt >= k:
                return True
        return False

    def aggressiveCows(self, stalls, k):
        n = len(stalls)
        stalls.sort()
        ans = 0
        i = 1
        j = max(stalls) - min(stalls)
        while i <= j:
            mid = i + (j - i) // 2
            if self.can_we_place(stalls, k, mid):
                ans = mid
                i = mid + 1
            else:
                j = mid - 1
        return ans


if __name__ == "__main__":
    object = Solution()
    stalls = [1, 2, 4, 8, 9]
    k = 3
    print(object.aggressiveCows(stalls, k))

    stalls = [10, 1, 2, 7, 5]
    k = 3
    print(object.aggressiveCows(stalls, k))

    stalls = [2, 12, 11, 3, 26, 7]
    k = 5
    print(object.aggressiveCows(stalls, k))

# Link: https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1


class Solution:
    def maxOccured(self, n, l, r, maxx):
        diff = [0] * (maxx + 2)

        for i in range(n):
            diff[l[i]] += 1
            diff[r[i] + 1] -= 1

        max_freq = 0
        result = 0
        curr_freq = 0
        for i in range(maxx + 1):
            curr_freq += diff[i]
            if curr_freq > max_freq:
                max_freq = curr_freq
                result = i

        return result


if __name__ == "__main__":
    obj = Solution()
    l = [1, 4, 3, 1]
    r = [15, 8, 5, 4]
    maxx = 15
    n = len(l)
    print(obj.maxOccured(n, l, r, maxx))

    l = [1, 5, 9, 13, 21]
    r = [15, 8, 12, 20, 30]
    maxx = 30
    n = len(l)
    print(obj.maxOccured(n, l, r, maxx))

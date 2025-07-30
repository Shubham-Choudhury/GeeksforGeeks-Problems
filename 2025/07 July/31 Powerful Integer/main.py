# Link: https://www.geeksforgeeks.org/problems/powerfull-integer--170647/1


class Solution:
    def powerfulInteger(self, intervals, k):
        mpp = {}

        for start, end in intervals:
            mpp[start] = mpp.get(start, 0) + 1
            mpp[end + 1] = mpp.get(end + 1, 0) - 1

        ans = -1
        temp = 0

        for point in sorted(mpp):
            delta = mpp[point]

            if delta >= 0:
                temp += delta
                if temp >= k:
                    ans = point
            else:
                if temp >= k:
                    ans = point - 1
                temp += delta

        return ans


if __name__ == "__main__":
    sol = Solution()
    intervals = [[1, 3], [4, 6], [3, 4]]
    k = 2
    result = sol.powerfulInteger(intervals, k)
    print(f"Powerful Integer: {result}")

    intervals = [[1, 4], [12, 45], [3, 8], [10, 12]]
    k = 3
    result = sol.powerfulInteger(intervals, k)
    print(f"Powerful Integer: {result}")

    intervals = [[16, 21], [5, 8], [12, 17], [17, 29], [9, 24]]
    k = 3
    result = sol.powerfulInteger(intervals, k)
    print(f"Powerful Integer: {result}")

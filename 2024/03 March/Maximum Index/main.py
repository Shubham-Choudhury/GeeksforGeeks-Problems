# Link: https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1


class Solution:
    def maxIndexDiff(self, a, n):
        st = []
        for i in range(n - 1, -1, -1):
            if len(st) == 0 or st[-1][1] < a[i]:
                st.append((i, a[i]))
        ans = 0
        for i in range(n):
            while len(st) > 0 and st[-1][1] >= a[i]:
                ans = max(ans, st[-1][0] - i)
                st.pop()
        return ans


if __name__ == "__main__":
    obj = Solution()
    a = [1, 10]
    n = len(a)
    print(obj.maxIndexDiff(a, n))
    a = [34, 8, 10, 3, 2, 80, 30, 33, 1]
    n = len(a)
    print(obj.maxIndexDiff(a, n))

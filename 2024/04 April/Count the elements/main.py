# Link: https://www.geeksforgeeks.org/problems/count-the-elements1529/1


class Solution:
    def countElements(self, a, b, n, query, q):
        b.sort()
        ans = []
        for x in query:
            left, right = 0, n - 1
            while left <= right:
                mid = left + (right - left) // 2
                if b[mid] <= a[x]:
                    left = mid + 1
                else:
                    right = mid - 1

            ans.append(left)

        return ans


if __name__ == "__main__":
    obj = Solution()
    a = [4, 1, 2]
    b = [1, 7, 3]
    n = len(b)
    query = [0, 1]
    q = len(query)
    print(obj.countElements(a, b, n, query, q))

    a = [1, 1, 5, 5]
    b = [0, 1, 2, 3]
    n = len(b)
    query = [0, 1, 2, 3]
    q = len(query)
    print(obj.countElements(a, b, n, query, q))

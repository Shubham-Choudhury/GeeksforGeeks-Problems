# Link: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1


class Solution:
    def nextLargerElement(self, arr):
        n = len(arr)
        ans = [0] * n

        st = []
        for i in range(n - 1, -1, -1):
            while st and arr[i] >= st[-1]:
                st.pop()
            if not st:
                ans[i] = -1
            else:
                ans[i] = st[-1]
            st.append(arr[i])
        return ans


if __name__ == "__main__":
    object = Solution()
    arr = [1, 3, 2, 4]
    result = object.nextLargerElement(arr)
    print(" ".join(map(str, result)))

    arr = [6, 8, 0, 1, 3]
    result = object.nextLargerElement(arr)
    print(" ".join(map(str, result)))

    arr = [10, 20, 30, 50]
    result = object.nextLargerElement(arr)
    print(" ".join(map(str, result)))

    arr = [50, 40, 30, 10]
    result = object.nextLargerElement(arr)
    print(" ".join(map(str, result)))

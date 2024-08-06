# Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1


class Solution:
    def kthElement(self, arr1, arr2, k):
        m = len(arr1)
        n = len(arr2)
        ans = []
        i = 0
        j = 0
        while i < m and j < n:
            if arr1[i] < arr2[j]:
                ans.append(arr1[i])
                i += 1
            else:
                ans.append(arr2[j])
                j += 1
        while i < m:
            ans.append(arr1[i])
            i += 1
        while j < n:
            ans.append(arr2[j])
            j += 1
        return ans[k - 1]


if __name__ == "__main__":
    obj = Solution()
    arr1 = [2, 3, 6, 7, 9]
    arr2 = [1, 4, 8, 10]
    k = 5
    print(obj.kthElement(arr1, arr2, k))

    arr1 = [100, 112, 256, 349, 770]
    arr2 = [72, 86, 113, 119, 265, 445, 892]
    k = 7
    print(obj.kthElement(arr1, arr2, k))

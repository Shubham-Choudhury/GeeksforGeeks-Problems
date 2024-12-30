# Link: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1


class Solution:
    def findUnion(self, arr1, arr2, n, m):
        """
        :param a: given sorted array a
        :param n: size of sorted array a
        :param b: given sorted array b
        :param m: size of sorted array b
        :return:  The union of both arrays as a list
        """
        ans = []
        i, j = 0, 0
        flag = False
        while i < n and j < m:
            if i > 0 and arr1[i] == arr1[i - 1]:
                i += 1
                flag = True
            if j > 0 and arr2[j] == arr2[j - 1]:
                j += 1
                flag = True

            if flag:
                flag = False
                continue

            if arr1[i] < arr2[j]:
                ans.append(arr1[i])
                i += 1
            elif arr2[j] < arr1[i]:
                ans.append(arr2[j])
                j += 1
            else:
                ans.append(arr1[i])
                i += 1
                j += 1

        while i < n:
            if i == 0 or arr1[i] != arr1[i - 1]:
                ans.append(arr1[i])
            i += 1

        while j < m:
            if j == 0 or arr2[j] != arr2[j - 1]:
                ans.append(arr2[j])
            j += 1

        return ans


if __name__ == "__main__":
    obj = Solution()

    arr1 = [1, 2, 3, 4, 5]
    arr2 = [1, 2, 3, 6, 7]
    n = len(arr1)
    m = len(arr2)
    ans = obj.findUnion(arr1, arr2, n, m)

    arr1 = [2, 2, 3, 4, 5]
    arr2 = [1, 1, 2, 3, 4]
    n = len(arr1)
    m = len(arr2)
    ans = obj.findUnion(arr1, arr2, n, m)

    arr1 = [1, 1, 1, 1, 1]
    arr2 = [2, 2, 2, 2, 2]
    n = len(arr1)
    m = len(arr2)
    ans = obj.findUnion(arr1, arr2, n, m)

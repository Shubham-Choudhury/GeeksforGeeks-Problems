# Link: https://www.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1


class Solution:
    def maxPathSum(self, arr1, arr2):
        sum1 = 0
        sum2 = 0
        n1 = len(arr1)
        n2 = len(arr2)
        i = n1 - 1
        j = n2 - 1

        while i >= 0 and j >= 0:
            if arr1[i] > arr2[j]:
                sum1 += arr1[i]
                i -= 1
            elif arr1[i] < arr2[j]:
                sum2 += arr2[j]
                j -= 1
            else:
                if sum1 > sum2:
                    sum1 += arr1[i]
                    sum2 = sum1
                else:
                    sum2 += arr2[j]
                    sum1 = sum2
                i -= 1
                j -= 1

        while i >= 0:
            sum1 += arr1[i]
            i -= 1

        while j >= 0:
            sum2 += arr2[j]
            j -= 1

        return max(sum1, sum2)


if __name__ == "__main__":
    obj = Solution()
    arr1 = [2, 3, 7, 10, 12]
    arr2 = [1, 5, 7, 8]
    print(obj.maxPathSum(arr1, arr2))

    arr1 = [1, 2, 3]
    arr2 = [3, 4, 5]
    print(obj.maxPathSum(arr1, arr2))

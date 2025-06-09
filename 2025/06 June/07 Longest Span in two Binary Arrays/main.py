# Link: https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1

class Solution:
    def longestCommonSum(self, arr1, arr2):
        n = len(arr1)
        res = 0
        diffMap = {}

        sum1 = 0
        sum2 = 0

        for i in range(n):
            sum1 += arr1[i]
            sum2 += arr2[i]

            currentDiff = sum1 - sum2

            if currentDiff == 0:
                res = max(res, i + 1)
            elif currentDiff in diffMap:
                res = max(res, i - diffMap[currentDiff])
            else:
                diffMap[currentDiff] = i

        return res
    
if __name__ == "__main__":
    obj = Solution()
    arr1 = [0, 1, 0, 0, 0, 0]
    arr2 = [1, 0, 1, 0, 0, 1]
    print(obj.longestCommonSum(arr1, arr2))

    arr1 = [0, 1, 0, 1, 1, 1, 1]
    arr2 = [1, 1, 1, 1, 1, 0, 1]
    print(obj.longestCommonSum(arr1, arr2))
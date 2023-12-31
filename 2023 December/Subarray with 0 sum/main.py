# Link: https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

# User function Template for python3


class Solution:
    # Function to check whether there is a subarray present with 0-sum or not.
    def subArrayExists(self, arr, n):
        ##Your code here
        # Return true or false
        res = set()
        count = 0
        if 0 in arr:
            return True
        else:
            for i in range(n):
                count += arr[i]
                if count == 0 or count in res:
                    return True
                res.add(count)
            return False


if __name__ == "__main__":
    obj = Solution()
    arr = [4, 2, -3, 1, 6]
    n = len(arr)
    print(obj.subArrayExists(arr, n))

    arr = [4, 2, 0, 1, 6]
    n = len(arr)
    print(obj.subArrayExists(arr, n))

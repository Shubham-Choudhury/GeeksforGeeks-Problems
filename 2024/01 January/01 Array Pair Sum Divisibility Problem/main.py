# Link: https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

class Solution:
    def canPair(self, nums, k):
        freq=[0]*k
        for i in range(len(nums)):
            freq[nums[i]%k]+=1
        if freq[0]%2!=0:
            return False
        for i in range(1,k):
            if freq[i]!=freq[k-i]:
                return False
        return True
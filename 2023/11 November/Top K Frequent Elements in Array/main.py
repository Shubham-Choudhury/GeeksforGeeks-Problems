# https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1

class Solution:
    def topK(self, nums, k):
        mp = {}
        for i in range(len(nums)):
            if nums[i] in mp:
                mp[nums[i]] += 1
            else:
                mp[nums[i]] = 1
        v = []
        for x in mp.items():
            v.append((x[1], x[0]))
        v.sort(reverse=True)
        ans = []
        for i in range(k):
            ans.append(v[i][1])
        return ans
    
if __name__ == '__main__':
    obj = Solution()
    nums = [1,1,1,2,2,3]
    k = 2
    print(obj.topK(nums, k))
    
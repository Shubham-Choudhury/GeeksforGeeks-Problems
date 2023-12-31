# Link: https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

class Solution:
	def pushZerosToEnd(self,arr, n):
		j=0
		for i in range(n):
			if arr[i]!=0:
				arr[i],arr[j]=arr[j],arr[i]
				j+=1
        return arr

obj = Solution()
arr = [1,2,0,4,3,0,5,0]
n = len(arr)
print(obj.pushZerosToEnd(arr,n))	

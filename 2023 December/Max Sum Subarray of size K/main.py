# Link: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#User function Template for python3
class Solution:
    def maximumSumSubarray (self,K,Arr,N):
        # code here
        l,h = 0,0
        tot = 0
        maxval = 0
        while h < N:
            if h-l+1 < K:
                tot += Arr[h]
                h +=1
            else:
                tot += Arr[h]
                maxval = max(maxval,tot)
                tot -= Arr[l]
                h += 1
                l += 1
        return maxval
                
if __name__=="__main__":
    obj=Solution()
    arr=[100, 200, 300, 400]
    n=len(arr)
    k=2
    print(obj.maximumSumSubarray(k,arr,n))
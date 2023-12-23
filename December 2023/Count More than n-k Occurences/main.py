# Link: https://www.geeksforgeeks.org/problems/count-element-occurences/1

class Solution:
    def countOccurence(self,arr,n,k):
        threshold = n // k
        frequency = {}
        for element in arr:
            if element in frequency:
                frequency[element] += 1
            else:
                frequency[element] = 1
        count = 0
        for key in frequency:
            if frequency[key] > threshold:
                count += 1

        return count
    
if __name__ == '__main__':
    obj=Solution()
    arr=[3,1,2,2,1,2,3,3]
    n=len(arr)
    k=4
    print(obj.countOccurence(arr,n,k))
    
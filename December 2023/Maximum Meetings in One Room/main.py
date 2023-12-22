# Link: https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

from typing import List

class Solution:
    def maxMeetings(self, N : int, S : List[int], F : List[int]) -> List[int]:
        # code here
        pairs=[]
        for i in range(N):
            pairs.append([S[i],F[i],i+1])
        pairs.sort(key=lambda x:x[1])
        count=[]
        curr=pairs[0][1]
        count.append(pairs[0][2])
        for i in range(1,N):
            if pairs[i][0]>curr:
                count.append(pairs[i][2])
                curr=pairs[i][1]
        count.sort()
        return count
    
if __name__ == '__main__':
    obj=Solution()
    N=6
    S=[1,3,0,5,8,5]
    F=[2,4,6,7,9,9]
    print(obj.maxMeetings(N,S,F))
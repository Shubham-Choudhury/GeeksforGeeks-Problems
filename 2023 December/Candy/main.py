# Link: https://www.geeksforgeeks.org/problems/candy/1


class Solution:
    def minCandy(self, N, ratings):
        candies = [1]*N
      
        for i in range(1,N):
            if ratings[i] > ratings[i-1]:
                candies[i] = candies[i-1]+1
        
        for i in range(N-1,0,-1):
            if ratings[i-1] > ratings[i] and candies[i-1] <= candies[i] : 
                candies[i-1] = candies[i] + 1
        return sum(candies)
        
if __name__=="__main__":
    obj=Solution()
    N=3
    ratings=[1,0,2]
    print(obj.minCandy(N, ratings))
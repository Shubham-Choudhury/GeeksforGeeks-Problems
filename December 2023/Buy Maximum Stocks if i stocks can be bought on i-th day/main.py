# Link: https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1

class Solution:
    def buyMaximumProducts(self, n, k, price):
        ans = 0
        for p, x in sorted([(x, i + 1) for i, x in enumerate(price)]):
            c = min(x, k // p)
            ans += c
            k -=  p * c
        return ans
    
if __name__=="__main__":
    obj = Solution()
    price =[10,7,19]
    n=len(price)
    k=45
    print(obj.buyMaximumProducts(n,k,price))
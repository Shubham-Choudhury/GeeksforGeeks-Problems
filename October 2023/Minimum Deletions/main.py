# Link: https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1

class Solution:
    def lps(self, string):
        n = len(string)
        L = [0] * n
        for i in range(n - 1, -1, -1):
            back_up = 0
            for j in range(i, n):
                if j == i:
                    L[j] = 1
                elif string[i] == string[j]:
                    temp = L[j]
                    L[j] = back_up + 2
                    back_up = temp
                else:
                    back_up = L[j]
                    L[j] = max(L[j], L[j - 1])
    
        return L[n - 1]
	
    def minimumNumberOfDeletions(self,S):
        n = len(S)
        length = self.lps(S)
        return (n - length)

if __name__ == "__main__":
    sol = Solution()
    S = "aebcbda"
    print("Minimum number of deletions =", sol.minimumNumberOfDeletions(S))
    S = "geeksforgeeks"
    print("Minimum number of deletions =", sol.minimumNumberOfDeletions(S))
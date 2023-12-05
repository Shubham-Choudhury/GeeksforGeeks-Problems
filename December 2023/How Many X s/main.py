# Link: https://www.geeksforgeeks.org/problems/how-many-xs4514/1

# User function Template for python3


class Solution:
    def count1(self, n, X):
        count = 0
        while n > 0:
            if n % 10 == X:
                count += 1
            n = n // 10
        return count

    def countX(self, L, R, X):
        # code here
        count = 0
        for i in range(L + 1, R):
            count += self.count1(i, X)
        return count


if __name__ == "__main__":
    obj = Solution()
    L = 10
    R = 19
    X = 1
    print(obj.countX(L, R, X))

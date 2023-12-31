# Link: https://www.geeksforgeeks.org/problems/sum-string3151/1


# User function Template for python3
class Solution:
    def isSumString(ob, s):
        # code here
        n = len(s)
        for i in range(1, n):
            for j in range(i + 1, n):
                x = int(s[:i])
                y = int(s[i:j])
                k = j
                while k < n:
                    z = x + y
                    sz = str(z)
                    if sz != s[k : k + len(sz)]:
                        break
                    x = y
                    y = z
                    k = k + len(sz)
                if k == n:
                    return 1

        return 0


if __name__ == "__main__":
    ob = Solution()
    print(ob.isSumString("12243660"))
    print(ob.isSumString("1111112223"))

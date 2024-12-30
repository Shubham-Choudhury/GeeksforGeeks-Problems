# Link: https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1

class Solution:
    def isRotated(self, str1, str2):
        s1 = ""
        n1 = len(str1)
        s1 += str1[2:n1]
        s1 += str1[0:2]
        s2 = ""
        s2 += str1[n1-2:n1]
        s2 += str1[0:n1-2]
        return (s1 == str2 or s2 == str2)

if __name__ == '__main__':
    obj=Solution()
    print(obj.isRotated("amazon","azonam"))
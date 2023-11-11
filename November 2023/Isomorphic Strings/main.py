# Link: https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

class Solution:
    def areIsomorphic(self, str1, str2):
        n = len(str1)
        m = len(str2)
        if n != m:
            return False
        mp = {}
        usedChar = set()
        for i in range(n):
            if str1[i] in mp:
                if mp[str1[i]] != str2[i]:
                    return False
            else:
                if str2[i] in usedChar:
                    return False
                mp[str1[i]] = str2[i]
                usedChar.add(str2[i])
        return True

if __name__ == '__main__':
    str1="aab"
    str2="xxy"
    ob = Solution()
    print(ob.areIsomorphic(str1,str2))
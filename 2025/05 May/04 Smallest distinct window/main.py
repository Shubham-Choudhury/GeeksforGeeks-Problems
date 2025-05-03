# Link: https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1


class Solution:
    def findSubString(self, str):
        st = set(str)
        count = len(st)
        mp = {}
        n = len(str)
        ans = n
        i = 0
        j = 0

        while j < n:
            mp[str[j]] = mp.get(str[j], 0) + 1
            while len(mp) == count:
                ans = min(ans, j - i + 1)
                mp[str[i]] -= 1
                if mp[str[i]] == 0:
                    del mp[str[i]]
                i += 1
            j += 1

        while len(mp) == count:
            ans = min(ans, j - i + 1)
            mp[str[i]] -= 1
            if mp[str[i]] == 0:
                del mp[str[i]]
            i += 1

        return ans


if __name__ == "__main__":
    obj = Solution()
    str = "aabcbcdbca"
    print("The length of the smallest distinct window is:", obj.findSubString(str))

    str = "aaab"
    print("The length of the smallest distinct window is:", obj.findSubString(str))

    str = "geeksforgeeks"
    print("The length of the smallest distinct window is:", obj.findSubString(str))

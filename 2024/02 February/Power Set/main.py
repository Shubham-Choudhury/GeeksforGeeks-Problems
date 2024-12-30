# Link: https://www.geeksforgeeks.org/problems/power-set4302/1


class Solution:
    def AllPossibleStrings(self, s):
        def dfs(s, sub_string, arr):
            if len(s) == 0:
                arr.append(sub_string)
                return
            cur_s = s[0]
            rem_s = s[1:]
            dfs(rem_s, sub_string, arr)
            dfs(rem_s, sub_string + cur_s, arr)

        arr = []
        dfs(s, "", arr)
        arr.remove("")
        return sorted(arr)


if __name__ == "__main__":
    obj = Solution()
    s = "abc"
    print(obj.AllPossibleStrings(s))
    s = "aa"
    print(obj.AllPossibleStrings(s))

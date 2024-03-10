# Link: https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1


class Solution:
    def removeDuplicates(self, str):
        s = ""
        for i in range(0, len(str)):
            if str[i] not in s:
                s = s + str[i]
        return s


if __name__ == "__main__":
    obj = Solution()
    str = "geEksforGEeks"
    print(obj.removeDuplicates(str))
    str = "HaPpyNewYear"
    print(obj.removeDuplicates(str))

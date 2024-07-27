# Link: https://www.geeksforgeeks.org/problems/remove-duplicates3034/1


class Solution:
    def removeDups(self, str):
        unique = [0] * 128
        result = ""

        for char in str:
            if unique[ord(char)] == 0:
                result += char
                unique[ord(char)] = 1
        return result


if __name__ == "__main__":
    obj = Solution()

    s = "zvvo"
    print(obj.removeDups(s))

    s = "gfg"
    print(obj.removeDups(s))

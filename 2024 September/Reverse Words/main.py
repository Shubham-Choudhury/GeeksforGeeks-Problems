# Link: https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1


class Solution:
    def reverseWords(self, str):
        temp = []
        t = ""

        for i in range(len(str)):
            if str[i] == ".":
                temp.append(t)
                t = ""
            else:
                t += str[i]
            if i == len(str) - 1:
                temp.append(t)

        ans = ""

        for i in range(len(temp) - 1, -1, -1):
            ans += temp[i]
            if i != 0:
                ans += "."

        return ans


if __name__ == "__main__":
    obj = Solution()
    str1 = "i.like.this.program.very.much"
    print(obj.reverseWords(str1))

    str2 = "pqr.mno"
    print(obj.reverseWords(str2))

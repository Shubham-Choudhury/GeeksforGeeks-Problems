# Link: https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1


class Solution:
    def isValid(self, str):
        cnt = 0
        word = ""
        n = len(str)
        for i in range(n):
            if str[i] == ".":
                num = int(word) if word else -1
                if 0 <= num <= 255:
                    cnt += 1
                    word = ""
            else:
                word += str[i]
        if cnt == 3:
            num1 = int(word) if word else -1
            if 0 <= num1 <= 255:
                cnt += 1
        return 1 if cnt == 4 else 0


if __name__ == "__main__":
    obj = Solution()
    str1 = "222.111.111.111"
    print(obj.isValid(str1))

    str2 = "5555..555"
    print(obj.isValid(str2))

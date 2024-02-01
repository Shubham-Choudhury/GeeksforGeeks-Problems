# Link: https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1


class Solution:
    def checkPangram(self, s):
        s = s.lower()
        count = 0
        for i in range(97, 123):
            if chr(i) in s:
                count += 1
        if count == 26:
            return True
        else:
            return False


if __name__ == "__main__":
    obj = Solution()
    s = "Bawds jog, flick quartz, vex nymph"
    print(obj.checkPangram(s))
    s = "sdfs"
    print(obj.checkPangram(s))

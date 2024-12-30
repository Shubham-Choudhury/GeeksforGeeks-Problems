# Link: https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1


class Solution:
    def printMinNumberForPattern(ob, S):
        ans = ""
        i = 0
        cur = 1
        dCount = 0
        while i < len(S):
            ch = S[i]
            if i == 0 and ch == "I":
                ans += str(cur)
                cur += 1
            if ch == "D":
                dCount += 1
            j = i + 1
            while j < len(S) and S[j] == "D":
                dCount += 1
                j += 1
            k = dCount
            while dCount >= 0:
                ans += str(cur + dCount)
                dCount -= 1
            cur += k + 1
            dCount = 0
            i = j

        return ans


if __name__ == "__main__":
    obj = Solution()
    S = "D"
    print(obj.printMinNumberForPattern(S))
    S = "IDD"
    print(obj.printMinNumberForPattern(S))

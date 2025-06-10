# Link: https://www.geeksforgeeks.org/problems/exactly-one-swap--170637/1


class Solution:
    def countStrings(self, s):
        n = len(s)
        map = [0] * 26
        ans = 0

        for i in range(n):
            ans += i - map[ord(s[i]) - ord("a")]
            map[ord(s[i]) - ord("a")] += 1

        for i in range(26):
            if map[i] > 1:
                ans += 1
                break

        return ans


if __name__ == "__main__":
    obj = Solution()
    s = "geek"
    print(obj.countStrings(s))

    s = "aaaa"
    print(obj.countStrings(s))

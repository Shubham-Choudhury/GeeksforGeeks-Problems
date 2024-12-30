# Link: https://www.geeksforgeeks.org/problems/game-with-string4100/1


from collections import defaultdict


class Solution:
    def minValue(self, s, k):
        char_count = defaultdict(int)
        for char in s:
            char_count[char] += 1
        values = list(char_count.values())
        values.sort()
        while k != 0:
            values[-1] -= 1
            k = k - 1
            values.sort()
        sum = 0
        for ele in values:
            sum += ele**2
        return sum


if __name__ == "__main__":
    obj = Solution()
    s = "abccc"
    k = 1
    print(obj.minValue(s, k))
    s = "aabcbcbcabcc"
    k = 3
    print(obj.minValue(s, k))

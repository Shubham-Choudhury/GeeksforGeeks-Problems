# Link: https://www.geeksforgeeks.org/problems/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645/1


class Solution:
    def minRepeats(self, s1, s2):
        ss1 = set(s1)
        ss2 = set(s2)

        for k in ss2:
            if k not in ss1:
                return -1

        count = 1
        c = len(s2)
        new_s1 = s1

        while len(new_s1) <= 2 * c:
            if new_s1.find(s2) != -1:
                return count
            count += 1
            new_s1 += s1

        if new_s1.find(s2) != -1:
            return count

        return -1


if __name__ == "__main__":
    object = Solution()
    s1, s2 = "ww", "www"
    print(object.minRepeats(s1, s2))

    s1, s2 = "abcd", "cdabcdab"
    print(object.minRepeats(s1, s2))

    s1, s2 = "ab", "cab"
    print(object.minRepeats(s1, s2))

# Link: https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1


class Solution:
    def areRotations(self, s1, s2):
        if len(s1) != len(s2):
            return False

        str_combined = s1 + s1

        return s2 in str_combined


if __name__ == "__main__":
    object = Solution()
    s1, s2 = "abcd", "cdab"
    print(object.areRotations(s1, s2))

    s1, s2 = "aab", "aba"
    print(object.areRotations(s1, s2))

    s1, s2 = "abcd", "acbd"
    print(object.areRotations(s1, s2))

# Link: https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1


class Solution:
    def areRotations(self, s1, s2):
        n = len(s1)
        if n != len(s2):
            return False
        s3 = s1 * 2
        for i in range(n):
            if s3[i : i + n] == s2:
                return True

        return False


if __name__ == "__main__":
    obj = Solution()
    s1 = "geeksforgeeks"
    s2 = "forgeeksgeeks"
    print(obj.areRotations(s1, s2))
    s1 = "mightandmagic"
    s2 = "andmagicmigth"
    print(obj.areRotations(s1, s2))

# Link: https://www.geeksforgeeks.org/problems/anagram-1587115620/1


class Solution:
    def areAnagrams(self, s1, s2):
        n1, n2 = len(s1), len(s2)
        arr1 = [0] * 26
        arr2 = [0] * 26
        for i in range(n1):
            arr1[ord(s1[i]) - ord("a")] += 1
        for i in range(n2):
            arr2[ord(s2[i]) - ord("a")] += 1
        for i in range(26):
            if arr1[i] != arr2[i]:
                return False
        return True


if __name__ == "__main__":
    object = Solution()
    s1, s2 = "geeks", "kseeg"
    print(object.areAnagrams(s1, s2))
    s1, s2 = "allergy", "allergic"
    print(object.areAnagrams(s1, s2))
    s1, s2 = "g", "g"
    print(object.areAnagrams(s1, s2))

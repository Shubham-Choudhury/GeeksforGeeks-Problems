# Link: https://www.geeksforgeeks.org/problems/print-anagrams-together/1


class Solution:
    def anagrams(self, arr):
        anagram_map = {}
        for str in arr:
            sorted_str = "".join(sorted(str))
            if sorted_str not in anagram_map:
                anagram_map[sorted_str] = []
            anagram_map[sorted_str].append(str)

        result = []
        added_groups = set()

        for str in arr:
            sorted_str = "".join(sorted(str))
            if sorted_str not in added_groups:
                result.append(anagram_map[sorted_str])
                added_groups.add(sorted_str)

        return result


if __name__ == "__main__":
    object = Solution()
    arr = ["act", "god", "cat", "dog", "tac"]
    result = object.anagrams(arr)
    for group in result:
        print(" ".join(group))
    print()

    arr = ["no", "on", "is"]
    result = object.anagrams(arr)
    for group in result:
        print(" ".join(group))
    print()

    arr = ["listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"]
    result = object.anagrams(arr)
    for group in result:
        print(" ".join(group))
    print()

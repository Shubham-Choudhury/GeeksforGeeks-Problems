# Link: https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1


class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isEnd = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for ch in word:
            idx = ord(ch) - ord("a")
            if not node.children[idx]:
                node.children[idx] = TrieNode()
            node = node.children[idx]
        node.isEnd = True

    def allPrefixesExist(self, word):
        node = self.root
        for ch in word:
            idx = ord(ch) - ord("a")
            node = node.children[idx]

            if not node or not node.isEnd:
                return False
        return True


class Solution:
    def longestString(self, arr):
        trie = Trie()

        for word in arr:
            trie.insert(word)

        result = ""

        for word in arr:
            if trie.allPrefixesExist(word):
                if len(word) > len(result) or (
                    len(word) == len(result) and word < result
                ):
                    result = word

        return result


if __name__ == "__main__":
    sol = Solution()
    arr = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
    result = sol.longestString(arr)
    print(f"Longest string: {result}")

    arr = ["ab", "a", "abc", "abd"]
    result = sol.longestString(arr)
    print(f"Longest string: {result}")

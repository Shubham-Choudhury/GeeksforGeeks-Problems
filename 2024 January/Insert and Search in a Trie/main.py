# Link: https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1


class TrieNode:
    def __init__(self):
        self.children = [None] * 26

        # isEndOfWord is True if node represent the end of the word
        self.isEndOfWord = False


class Solution:
    # Function to insert string into TRIE.
    def insert(self, root, key):
        # code here
        for k in key:
            ind = ord(k) - ord("a")
            if not root.children[ind]:
                root.children[ind] = TrieNode()
            root = root.children[ind]
        root.isEndOfWord = True

    # Function to use TRIE data structure and search the given string.
    def search(self, root, key):
        # code here
        for k in key:
            ind = ord(k) - ord("a")
            if not root.children[ind]:
                return False
            root = root.children[ind]
        return root.isEndOfWord


if __name__ == "__main__":
    obj = Solution()
    n = 8
    lst = ["the", "a", "there", "any", "by", "bye", "theiir"]
    key = "the"
    root = TrieNode()
    for i in lst:
        obj.insert(root, i)
    print(obj.search(root, key))

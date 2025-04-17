# Link: https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1


class Trie:
    def __init__(self):
        self.root = {}

    def insert(self, word: str):
        cur = self.root
        for c in word:
            if c not in cur:
                cur[c] = {}
            cur = cur[c]
        cur["."] = {}

    def search(self, word: str) -> bool:
        cur = self.root
        for c in word:
            if c not in cur:
                return False
            cur = cur[c]
        return "." in cur

    def isPrefix(self, word: str) -> bool:
        cur = self.root
        for c in word:
            if c not in cur:
                return False
            cur = cur[c]
        return True


if __name__ == "__main__":
    t1 = Trie()
    l = ["abcd", "abc", "bcd"]
    for i in l:
        t1.insert(i)
    print(t1.search("bc"))
    print(t1.isPrefix("bc"))
    print(t1.search("abc"))

    t2 = Trie()
    l = ["gfg", "geeks"]
    for i in l:
        t2.insert(i)
    print(t2.isPrefix("fg"))
    print(t2.isPrefix("geek"))
    print(t2.search("for"))

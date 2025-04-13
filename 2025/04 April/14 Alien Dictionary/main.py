# Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1


class Solution:
    def findOrder(self, words):
        adj = {c: [] for w in words for c in w}
        indeg = {c: 0 for c in adj}
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]
            for j in range(min(len(w1), len(w2))):
                if w1[j] != w2[j]:
                    if w2[j] not in adj[w1[j]]:
                        adj[w1[j]].append(w2[j])
                        indeg[w2[j]] += 1
                    break
            else:
                if len(w1) > len(w2):
                    return ""
        res = []
        q = [c for c in indeg if indeg[c] == 0]
        while q:
            c = q.pop()
            res.append(c)
            for n in adj[c]:
                indeg[n] -= 1
                if indeg[n] == 0:
                    q.append(n)
        return "".join(res) if len(res) == len(indeg) else ""


if __name__ == "__main__":
    sol = Solution()
    words = ["cb", "cba", "a", "bc"]
    order = sol.findOrder(words)
    if order:
        print("The order of characters is:", order)
    else:
        print("There is no valid order of characters.")

    words = ["ab", "aa", "a"]
    order = sol.findOrder(words)
    if order:
        print("The order of characters is:", order)
    else:
        print("There is no valid order of characters.")

    words = ["ab", "cd", "ef", "ad"]
    order = sol.findOrder(words)
    if order:
        print("The order of characters is:", order)
    else:
        print("There is no valid order of characters.")
